from collections import Counter
class Solution:
    def canReorderDoubled(self, arr: List[int]) -> bool:
        arr.sort(reverse=True)
        c = Counter(arr)
        for x in arr:
            if c[x] > 0 and x*2 in c and c[x*2] > 0:
                c[x] -= 1
                c[x*2] -= 1

        for x in c.values():
            if x:
                return False

        return True
        