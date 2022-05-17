from itertools import accumulate
from collections import Counter

class Solution:
    def numSubmatrixSumTarget(self, matrix: List[List[int]], target: int) -> int:
        m, n = len(matrix), len(matrix[0])
        prefixSums = list(map(lambda row: list(accumulate(row)), matrix))
        cnt = 0
        for i in range(n): # start of column we care about
            for j in range(i, n): # end of the column we care about
                counter = Counter()
                curSum, counter[0] = 0, 1 
                for k in range(m):
                    # i-1 removes the value of the prefix row till that point
                    prevRowVal = prefixSums[k][i-1] if i else 0
                    curSum += prefixSums[k][j] - prevRowVal 
                    cnt += counter[curSum - target]
                    counter[curSum] += 1

        return cnt