from bisect import bisect_left
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        piles = []
        for x in nums:
            if piles and piles[-1] >= x:
                i = bisect_left(piles, x)
                piles[i] = x
            else:
                piles.append(x)
        return len(piles)
