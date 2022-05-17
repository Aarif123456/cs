from collections import defaultdict

class Solution:
    def minTransfers(self, transactions: List[List[int]]) -> int:
        def createDeptList(transactions):
            debt = defaultdict(int)
            for s, e, w in transactions:
                debt[s]-=w
                debt[e]+=w

            return [x for x in debt.values() if x != 0]

        def dfs(s: int, debt: list):
            n = len(debt)
            while s < n and debt[s] == 0:
                s += 1
            # print(debt)
            best, prev = None, 0
            for i in range(s+1, n):
                if debt[i] != prev and (debt[i] * debt[s]) < 0:
                    debt[i] += debt[s]
                    curStep = 1 + dfs(s+1, debt)
                    best = min(best, curStep) if best is not None else curStep
                    debt[i] -= debt[s]
                    prev = debt[i]


            return best if best is not None else 0
        debt = createDeptList(transactions)
        

        return dfs(0, debt)