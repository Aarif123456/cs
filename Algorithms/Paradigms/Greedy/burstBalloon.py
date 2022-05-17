class Solution:
    def findMinArrowShots(self, segments: List[List[int]]) -> int:
        segments.sort(key=lambda a: a[1]) # sort by ending
        points = 0
        lastIntervalEnd = None

        for seg in segments:
            # if our endings do not contain this line start new interval
            if not lastIntervalEnd or seg[0] > lastIntervalEnd:
                points += 1
                lastIntervalEnd = seg[1]
            
        return points
