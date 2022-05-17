class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        nums.sort()
        def kSums(nums, start, target, k):
            if k < 2: raise ValueError(" k must be bigger than 2")
            if k == 2: return twoSums(nums, start, target)
            ans, n = set(), len(nums)
            for i in range(start, n):
                x = nums[i]
                pairs = kSums(nums, i+1, target-x, k-1)
                for p in pairs:
                    ans.add((x, *p))
            return ans

        def twoSums(nums, start, target):
            i, j, ans = start, len(nums) - 1, set()
            while i < j:
                if nums[i] + nums[j] == target:
                    ans.add((nums[i], nums[j]))
                    i += 1
                    j -= 1
                elif nums[i] + nums[j] < target:
                    i += 1
                else: # bigger than target
                    j -= 1

            return ans

        ans = kSums(nums, 0, target, 4)

        return [list(p) for p in ans]