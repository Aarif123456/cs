class Solution:
    def largestIsland(self, grid: List[List[int]]) -> int:
        
        def fillIslandSizes(i, j, islandNum):
            nonlocal grid, islandSizes, m, n
            size = 0
            if i >= 0 and j >= 0 and i < m and j < n and grid[i][j] == 1:
                size += 1
                for dx, dy in (0,1), (0,-1), (1,0), (-1,0):
                    grid[i][j] = -islandNum
                    size += fillIslandSizes(i+dx, j+dy, islandNum)

            return size

        def getCombinedAreaAfterFill(i, j):
            nonlocal grid, islandSizes, m, n
            size = 1
            neighbourIslands = set()
            for dx, dy in (0,1), (0,-1), (1,0), (-1,0):
                ni, nj = i+dx, j+dy
                if ni >= 0 and nj >= 0 and ni < m and nj < n and grid[ni][nj] < 0:
                    neighbourIslands.add(-grid[ni][nj])

            for islandNum in neighbourIslands:
                size += islandSizes[islandNum]

            return size


        islandSizes = [0]
        n,m = len(grid), len(grid[0])
        for i, row in enumerate(grid):
            for j, cell in enumerate(row):
                if cell == 1:
                    size = fillIslandSizes(i, j, len(islandSizes))
                    islandSizes.append(size)

        # print(islandSizes)
        bestSize = max(islandSizes)
        for i, row in enumerate(grid):
            for j, cell in enumerate(row):
                if cell == 0:
                    combSize = getCombinedAreaAfterFill(i, j)
                    bestSize = max(bestSize, combSize)

        return bestSize