from itertools import accumulate
class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prefix = [1]+list(accumulate(nums[:-1], lambda a,b: a*b))
        suffix = list(accumulate(nums[::-1][:-1], lambda a,b: a*b))[::-1] + [1]
        return [a[0]*a[1] for a in zip(prefix, suffix)]
