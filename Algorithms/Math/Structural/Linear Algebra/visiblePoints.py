class Solution:
    def visiblePoints(self, points: List[List[int]], angle: int, location: List[int]) -> int:
        fullTurn, halfTurn = math.pi*2, math.pi
        shiftx, shifty = location
        sameCount = sum([x==shiftx and y==shifty for x, y in points])
        points = [[x - shiftx, y - shifty] for x, y in points if x != shiftx or y != shifty]
        degrees = [math.atan2(y, x) for x, y in points]
        degrees.sort()
        degrees += [deg + fullTurn for deg in degrees]
        winEnd, maxWindowSize, n = 0, 0, len(points)
        angle = math.radians(angle)
        # print(degrees)
        # print(angle)
        # print(sameCount)
        # print()
        # we try to expand the window as much as you can 
        # if we move our start we can see all the element we could see previously
        # that are to the right 
        for winStart, startDegree in enumerate(degrees):
            while winEnd < len(degrees) and\
                    degrees[winEnd] - startDegree  <= angle:
                winEnd += 1
            maxWindowSize = max(maxWindowSize, winEnd-winStart)
            # print(f"{winStart}, {winEnd}")
            # print(f"start:{startDegree}, size={winEnd-winStart}")

        return maxWindowSize + sameCount



        