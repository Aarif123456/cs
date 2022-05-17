class Solution:
    """
    @param A: a sparse matrix
    @param B: a sparse matrix
    @return: the result of A * B
    """
    def multiply(self, A, B):
        aRow = len(A)
        aCol = len(A[0])
        bRow = len(B)
        bCol = len(B[0])

        assert(aCol == bRow)
        # for each row in A - go through and find the next non zero column in the same row
        nextNonZeroRowA = [[-1] * aCol for _ in range(aRow)]
        # for each Col in B - go through and find the next non zero row in the same column
        nextNonZeroColB = [[-1] * bCol for _ in range(bRow)]

        # O(n^2)
        for rowNum, row in enumerate(A):
            nextNonZero = -1
            for colNum in range(aCol-1, -1, -1):
                if row[colNum] != 0:
                    nextNonZero = colNum
                nextNonZeroRowA[rowNum][colNum] = nextNonZero

        # print(nextNonZeroRowA)
        # O(n^2)
        for colNum in range(bCol):
            nextNonZero = -1
            for rowNum in range(bRow-1, -1, -1):
                row = B[rowNum]
                if row[colNum] != 0:
                    nextNonZero = rowNum
                nextNonZeroColB[rowNum][colNum] = nextNonZero          
        # print(nextNonZeroColB)

        out  = []
        for rowNum, row in enumerate(A):
            rowAns = []
            for curBCol in range(bCol):
                ans = 0
                for cur in range(bRow): # cur goes through B's column but A's row
                    # print(f"rowNum:{rowNum}, curBCol:{curBCol}, cur:{cur}")
                    if nextNonZeroRowA[rowNum][cur] == -1 or nextNonZeroColB[cur][curBCol] == -1: break
                    ans += row[cur] * B[cur][curBCol]
                    if cur < bRow-1:
                        cur = max(nextNonZeroRowA[rowNum][cur+1], nextNonZeroColB[cur+1][curBCol])
                rowAns.append(ans)
            out.append(rowAns)
        return out

sol = Solution()
# A = [[2,3,4],[0,0,0]]
# B = [[1,2],[3,4],[5,6]]
# A = [[1,0,0],[-1,0,3]]
# B = [[7,0,0,1,2],[0,0,0,1,2],[0,0,1,1,2]]
# A = [[1,0,0],[-1,0,3],[-1,0,3],[-1,0,3],[-1,0,3],[-1,0,3],[-1,0,3],[-1,0,3],[-1,0,3],[-1,0,3],[-1,0,3],[-1,0,3],[-1,0,3]]
# B = [[7,0,0,1,2],[0,0,0,1,2],[0,0,1,1,2]]

# print(sol.multiply(A, B))