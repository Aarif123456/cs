class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        counter = collections.defaultdict(int)
        for x in nums: counter[x] += 1

        pq = []
        for x in counter.keys():
            heapq.heappush(pq, (counter[x], x))
            if len(pq) > k:
                heapq.heappop(pq)


        return [a[1] for a in pq]
        