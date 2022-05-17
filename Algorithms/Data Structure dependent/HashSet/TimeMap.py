from bisect import bisect_right
from collections import defaultdict
# in c++ use map and just find lower bound 
class TimeMap:
    def __init__(self):
        self.timeMap = defaultdict(list)
        self.valMap = {}

    def set(self, key: str, value: str, timestamp: int) -> None:
        if f"{key}:{timestamp}" not in self.valMap:
            self.timeMap[key].append(timestamp)
            # no need cause given in increasing order
            # insort(self.timeMap[key], timestamp) 
        self.valMap[f"{key}:{timestamp}"] = value

    def get(self, key: str, timestamp: int) -> str:
        i = bisect_right(self.timeMap[key], timestamp)-1
        if not self.timeMap[key] or self.timeMap[key][i] > timestamp: 
            return ""
        timestamp_prev = self.timeMap[key][i]
        return self.valMap[f"{key}:{timestamp_prev}"]
