class Solution:
    def carPooling(self, intervals: List[List[int]], capacity: int) -> bool:
        # sort by biggest ending first
        intervals = sorted(intervals, reverse=True, key=lambda a: a[2])
        # go through and add in start time to max-heap 
        pq = []
        curPass = 0
        for numPass, start, end in intervals:
            # pop-out elements from max-heap 
            # while current end time is smaller than the start time
            while len(pq) and end <= -pq[0][0]:
                _, pas = heappop(pq)
                curPass -= pas

            # hacky way to keep our biggest start time at top
            heappush(pq, (-start, numPass))
            curPass += numPass
            # track the size of the max-heap 
            if curPass > capacity: return False
        # return the biggest value we see
        return True