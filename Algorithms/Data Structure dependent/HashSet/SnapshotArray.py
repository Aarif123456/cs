from bisect import bisect_right
class SnapshotArray:
    def __init__(self, length: int):
        self.vals = {}
        self.snapVal = 0
        self.lastUpdated=[[] for  _ in range(length)]

    def set(self, index: int, val: int) -> None:
        key = f"{index}:{self.snapVal}"
        # if we haven't made a snap of the current value
        if key not in self.vals:
            self.lastUpdated[index].append(self.snapVal)

        self.vals[key] = val

    def snap(self) -> int:
        self.snapVal += 1
        return self.snapVal - 1

    def get(self, index: int, snapId: int) -> int:
        # find snap less than or equal to our value
        curSnaps = self.lastUpdated[index]
        i = bisect_right(curSnaps, snapId) - 1
        if i < 0 or curSnaps[i] > snapId :
            return 0
        key = f"{index}:{curSnaps[i]}"

        return self.vals[key]
        