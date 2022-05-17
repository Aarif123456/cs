from collections import defaultdict
class Solution:
    # So, we know the task(s) with the most frequent are the limiting factor
    # We can use them to calculate the min length they need to be done so 
    # they are k distance apart.

    def leastInterval(self, tasks: List[str], k: int) -> int:
        counter = defaultdict(int)
        for task in tasks:
            counter[task] += 1
        vals = list(counter.values())
        n = len(tasks)
        maxVal = max(vals)
        maxCount = vals.count(maxVal)
        # Put all the most frequent elements together 
        # how many spaces are i between
        emptySpots = (k-(maxCount-1))*(maxVal-1)
        leftOver = n - maxVal*maxCount
        numIdles = max(0, emptySpots - leftOver)

        return n + numIdles






