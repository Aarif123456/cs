from collections import defaultdict

class Solution:
    def customSortString(self, order: str, s: str) -> str:
        orderedMap = defaultdict(int)
        # def compare(a,b):
        #     nonlocal orderedMap 
        #     return orderedMap[a] < orderedMap[b]

        for i,c in enumerate(order):
            orderedMap[c] = i

        return "".join(sorted(s, key=lambda c: orderedMap[c]))