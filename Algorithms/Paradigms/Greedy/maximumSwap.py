class Solution:
    def maximumSwap(self, num: int) -> int:
        nums = list(str(num))
        n = len(nums)
        p1, p2 = n-1,n-1
        best = n-1
        for i in range(n-1, -1, -1):
            if nums[i] > nums[best]:
                best = i
            elif nums[i] < nums[best]:
                p1 = best
                p2 = i


        nums[p1], nums[p2] = nums[p2], nums[p1]

        return "".join(nums)
