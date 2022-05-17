class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        # sort by earliest deadline first - see what ever interval can be scheduled
        points.sort(key = lambda a: a[1])
        arrows, lastIntervalEnd = 0, None
        for start, end in points:
            # see if last interval can contain current interval
            if not lastIntervalEnd or lastIntervalEnd < start:
                arrows += 1
                lastIntervalEnd = end
        return arrows