from math import sqrt
class Solution:
    def kClosest(self, points: List[List[int]], k: int) -> List[List[int]]:

        pq = []

        points = [(-sqrt(x**2+y**2),x,y) for x,y in points]
        for val in points:
            heappush(pq, val)
            if len(pq) > k: heappop(pq)

        return [[x, y] for _, x, y in pq]