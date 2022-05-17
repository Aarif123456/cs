class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        newStart, newEnd = newInterval
        # interval is to the left if it ends before new interval start
        left = [[start, end] for start,end in intervals if end < newStart]
        # interval is to the right if it starts after new interval ends
        right = [[start, end] for start,end  in intervals if start > newEnd]

        # if some elements were merged 
        if left + right != intervals:
            n, nl, nr = len(intervals), len(left), len(right)
            # go to the first (lowest start) that overlaps and get it's start
            newStart = min(newStart, intervals[nl][0])
            # find the last element (biggest end) that overlaps - and get it's edn
            newEnd = max(newEnd, intervals[n-nr-1][1])

        return left + [(newStart, newEnd)] + right
