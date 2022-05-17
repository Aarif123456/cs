class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        sum = 0
        counter = {}
        counter[0] = 1
        ans = 0
        for n in nums:
            sum += n
            if sum-k in counter: ans += counter[sum-k]
            if sum not in counter: counter[sum] = 0
            counter[sum] += 1

        return ans