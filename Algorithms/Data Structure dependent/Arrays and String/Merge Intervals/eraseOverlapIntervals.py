from heapq import heappop, heappush

class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        # earliest first - we choose one that frees up the quickest
        intervals.sort(key=lambda a: a[1])
        count, curTime = 0, float("-inf")
        for start, end in intervals:
            # if we can schedule then schedule 
            if start >= curTime:
                count += 1
                curTime = end

        return len(intervals) - count



