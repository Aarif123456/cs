class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        m, n = len(points), len(points[0])
        reverse_enumerate = lambda l: zip(range(len(l)-1, -1, -1), reversed(l))
        for i, row in enumerate(points):
            if i == m-1:
                break
            bestSoFar, bestIndex = row[n-1], n-1
            for j, x in reverse_enumerate(row):
                if x > bestSoFar:
                    bestSoFar, bestIndex = x, j
                else:
                    points[i][j] = bestSoFar
                bestSoFar -= 1

            bestSoFar, bestIndex = row[0], 0
            for j, x in enumerate(row):
                if x > bestSoFar:
                    bestSoFar, bestIndex = x, j
                else:
                    points[i][j] = bestSoFar 
                bestSoFar -= 1
                points[i+1][j] += points[i][j]

        return max(points[-1])