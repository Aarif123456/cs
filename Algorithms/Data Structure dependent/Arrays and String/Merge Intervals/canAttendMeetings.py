class Solution:
    def canAttendMeetings(self, intervals: List[List[int]]) -> bool:
        # schedule earliest deadline because it frees up the quickest
        intervals.sort(key = lambda a: a[1])
        curTime = -1
        for start, end in intervals:
            # if this new task cannot be scheduled we are done
            if start < curTime: return False
            # otherwise schedule and book till end of task
            curTime = end

        return True