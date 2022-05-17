class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        n = len(position)
        timeReached = []
        for i in range(n):
            pos, sp = position[i], speed[i]
            timeReached.append((pos, (target-pos)/sp))

        timeReached.sort(key=lambda a: a[0], reverse=True)
        curTime, numFleets = -1, 0
        # print(timeReached)
        for _, time in timeReached:
            # car could not catch up to current fleet in time - so make new fleet
            if time > curTime:
                curTime = time
                numFleets += 1

        return numFleets



