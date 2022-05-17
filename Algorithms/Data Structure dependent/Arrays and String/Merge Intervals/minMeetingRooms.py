from heapq import heappop, heappush, heapreplace
class Solution:
    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        roomsEnds = []
        # sort by start first - because we are using the starting time to book room
        # if we do ending first - we get rid of rooms that end first early on - 
        # but by doing start first we can never eliminate rooms that could have been
        # used for the room - to create a better schedule - by the same reasoning
        # of why choosing first ending produces the optimal schedule - e.g. we know
        # first ending frees up faster - so that room becomes available 
        intervals.sort(key = lambda a: a[0])

        for start, end in intervals:
            # if the earliest room to become free will not be free by the time the appointment starts then make another room
            if not roomsEnds or roomsEnds[0] > start:
                heappush(roomsEnds, end)
            else: # otherwise replace the room that finished the earliest
                heapreplace(roomsEnds, end)

        return len(roomsEnds)

