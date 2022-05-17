class Solution:
    def maximalRectangle(self, matrix: List[List[str]]) -> int:
        if not matrix:
            return 0
        m, n = len(matrix), len(matrix[0])
        left, right, heights = [0]*n, [n]*n, [0]*n
        best = 0
        for row in matrix:
            curLeft, curRight = 0, n
            for i in range(n):
                if row[i] == "1":
                    heights[i] += 1
                else:
                    heights[i] = 0

            for i in range(n):
                if row[i] == "1":
                    left[i] = max(left[i], curLeft)
                else:
                    curLeft = i+1
                    left[i] = 0

            for i in range(n-1, -1, -1):
                if row[i] == "1":
                    right[i] = min(right[i], curRight)
                else:
                    curRight = i
                    right[i] = n

            for i in range(n):
                best = max(best, (right[i]-left[i]) * heights[i])

        return best





