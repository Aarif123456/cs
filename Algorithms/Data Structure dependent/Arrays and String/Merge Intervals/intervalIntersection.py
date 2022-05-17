class Solution:
    def intervalIntersection(self, firstList: List[List[int]], secondList: List[List[int]]) -> List[List[int]]:
        p1, p2, e1, e2 = 0, 0, len(firstList), len(secondList)
        out = []
        while p1 != e1 and p2 != e2:
            # your ending has to be bigger than my start and my start has to be bigger than your ending
            if firstList[p1][0] <= secondList[p2][1] and firstList[p1][1] >= secondList[p2][0]:
                out.append((max(firstList[p1][0], secondList[p2][0]), min(firstList[p1][1], secondList[p2][1])))
            if firstList[p1][1] < secondList[p2][1]:
                p1 += 1
            else:
                p2 += 1

        return out



        