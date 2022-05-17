class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key = lambda a: a[0])
        out = []
        curStart, curEnd = intervals[0]
        for start, end in intervals:
            if curEnd >= start:
                curEnd = max(end, curEnd)
            else:
                out.append((curStart, curEnd))
                curStart, curEnd = start ,end

        out.append((curStart, curEnd))
        return out 

