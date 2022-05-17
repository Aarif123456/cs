from queue import SimpleQueue
class Solution:
    def shortestPath(self, grid: List[List[int]], k: int) -> int:
        m, n = len(grid), len(grid[0])
        start, target = (0,0), (m-1, n-1)
        obstacles = set([(i, j) for i, row in enumerate(grid) for j, cell in enumerate(row) if cell == 1])

        q = SimpleQueue()
        q.put_nowait((*start, k, 0))
        seen = set()
        while not q.empty():
            curX, curY, k, d = q.get_nowait()
            if curX < 0 or curY < 0 or curX >= m or curY >= n or (curX, curY, k) in seen:
                continue
            if (curX, curY) == target:
                return d
            seen.add((curX, curY, k))

            for dx, dy in (0, 1), (0, -1), (1, 0), (-1, 0):
                nxtX, nxtY = curX+dx, curY+dy 
                # if not an obstacle just try and walk to it
                if (nxtX, nxtY) not in obstacles:
                    q.put_nowait((nxtX, nxtY, k, d+1))
                # otherwise try to destroy obstacle
                elif k:
                    q.put_nowait((nxtX, nxtY, k-1, d+1))

        return -1



