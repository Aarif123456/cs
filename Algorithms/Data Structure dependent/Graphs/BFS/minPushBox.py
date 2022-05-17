from heapq import heappop, heappush

class Solution:
    def minPushBox(self, grid: List[List[str]]) -> int:
        player, box, target = -1, -1, -1
        free = set([(i,j) for i, row in enumerate(grid) for j, cell in enumerate(row) if cell != "#"])
        for i, row in enumerate(grid):
            for j, cell in enumerate(row):
                if cell == "S": player = (i,j)
                elif cell == "B": box = (i,j)
                elif cell == "T": target = (i,j)
        # print(target)

        pq, seen = [(0, *player, *box)], set()

        while pq:
            # cp = currentPlayer - cb = currentBox
            d, cpx, cpy, cbx, cby = heappop(pq)
            if (cbx, cby) == target: return d 
            if (cpx, cpy, cbx, cby) in seen: continue
            seen.add((cpx, cpy, cbx, cby))
            # print(f"(cpx:{cpx}, cpy:{cpy}, cbx:{cbx}, cby:{cby})")
            for dx,dy in (0,1),(0,-1),(1,0),(-1,0):
                npx, npy, nbx, nby = cpx+dx, cpy+dy, cbx+dx, cby+dy
                # if player moves into box and box can move to next spot
                if (npx, npy) ==  (cbx, cby) and (nbx, nby) in free:
                    heappush(pq, (d+1, npx, npy, nbx, nby))
                # otherwise if player can move without going through the box
                elif (npx, npy) in free and (npx, npy) != (cbx, cby):
                    heappush(pq, (d, npx, npy, cbx, cby))

        return -1

