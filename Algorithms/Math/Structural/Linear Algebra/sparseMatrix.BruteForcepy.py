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
        out  = []
        for row in A:
            rowAns = []
            for curBRow in range(bRow):
                ans = 0
                for cur in range(bCol): # cur goes through B's column but A's row
                    ans += row[cur] * B[cur][curBRow]
                rowAns.append(ans)
            out.append(rowAns)
        return out
