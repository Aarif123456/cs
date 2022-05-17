from heapq import heappop, heappush

class Solution:
    def minRefuelStops(self, target: int, startFuel: int, stations: List[List[int]]) -> int:
        # idea track current place
        # if we can't reach our next destination fuel we use the best fuel we have so far
        DIST, FUEL = 0, 1
        curReach, fuelled, curStation, n = startFuel, 0, 0, len(stations)
        possibleFuels = []
        # print(stations)
        while curReach < target:
            while curStation < n and curReach >= stations[curStation][DIST]:
                heappush(possibleFuels, -stations[curStation][FUEL])
                curStation += 1

            if not possibleFuels:
                return -1
            curReach += -heappop(possibleFuels)
            fuelled += 1
                
        return fuelled

        