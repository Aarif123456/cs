class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        if not intervals: return [newInterval]
        # break apart for readability 
        newStart, newEnd = newInterval
        merged, n = [], len(intervals)
        i = 0
        while i < n:
            if intervals[i][0] >= newStart: break
            merged.append(intervals[i])
            i += 1
        merged.append(newInterval)

        while i < len(intervals):
            merged.append(intervals[i])
            i += 1

        curStart, curEnd = merged[0]
        out = []
        for start, end in merged:
            if curEnd >= start:
                curEnd = max(end, curEnd)
            else:
                out.append((curStart, curEnd))
                curStart, curEnd = start, end

        out.append((curStart, curEnd))

        return out
        