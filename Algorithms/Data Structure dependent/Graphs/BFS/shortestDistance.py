from queue import SimpleQueue
from math import isinf

class Solution:
    '''
        Idea fill-up dist-grid with distance to building
        and inf if a building cannot be reached
        We can do this for every cell in our grid for each our building

        If k = number of building
           n = number of row
           m = number of columns
        O(knm) - time
        O(nm) - space
    '''
    def shortestDistance(self, grid: List[List[int]]) -> int:
        distGrid = [[0 if x == 0 else float("inf") for x in row] for row in grid]
        m, n = len(grid), len(grid[0])
        nextX = [-1, 1, 0, 0]
        nextY = [0, 0, -1, 1]

        # bfs for min distance
        def fillGrid(x ,y):
            nonlocal distGrid, n, m, nextY, nextY            
            # mark visited - so we know what position are not reachable
            visited = [[False] * n for _ in range(m)]

            q = SimpleQueue()
            q.put_nowait((x, y, 0))
            while not q.empty():
                x, y, step = q.get_nowait()
                if x>=0 and y>=0 and x < m and y < n and not visited[x][y]:
                    visited[x][y] = True
                    if not isinf(distGrid[x][y]) or step == 0:
                        distGrid[x][y] += step
                        for i in range(4): q.put_nowait((x+nextX[i], y+nextY[i], step+1))
                    

            # mark unreachable cells
            for x in range(m):
                for y in range(n):
                    if not visited[x][y]: 
                        distGrid[x][y] = float("inf")

        for x in range(m):
            for y in range(n):
                if grid[x][y] == 1:
                    fillGrid(x, y)

        val = min([min(row) for row in distGrid])
        return val if not isinf(val) else -1


