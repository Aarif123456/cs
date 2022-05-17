class Solution:
    def maxScore(self, cardPoints: List[int], k: int) -> int:
        if k >= len(cardPoints): return sum(cardPoints)
        n = len(cardPoints)
        curSum = 0
        for i in range(k):
            curSum += cardPoints[-(i+1)]

        best = curSum 
        sep = n-k # the numbers are separated by n-k element
        for i in range(k):
            curSum += cardPoints[i]
            curSum -= cardPoints[sep+i]
            best = max(best,curSum)

        return best



        