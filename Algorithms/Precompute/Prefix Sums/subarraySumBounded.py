from itertools import accumulate

class Solution:
    def subarraySum(self, nums: list[int], target: int, k = None) -> int:
        if k is None: k = len(nums)
        if k > len(nums): k = len(nums)
        sum = 0
        counter = {0:1}
        ans = 0
        offset = 0
        for i,n in enumerate(nums):
            sum += n
            if i >= k: 
                offset += nums[i-k]
                counter[offset] -= 1
            # if two elements are target elements apart - the bounded constraint doesn't matter
            # print(sum)
            print(sum-target)
            # print(target+offset)
            print(counter)
            if sum not in counter: counter[sum] = 0

            if sum-target in counter: 
                ans += counter[sum-target]
                print("here")
            if target+offset in counter: 
                ans += counter[target+offset]

            counter[sum] += 1

        totLen = len(nums) 
        start = totLen-k
        for i in range(start, totLen-1):
            offset += nums[i]
            counter[offset] -= 1
            if (offset+nums[i+1] +target) in counter:
                ans += counter[nums[i+1] + offset+target]
            if (target+offset) in counter:
                ans += counter[0]

        return ans


sol = Solution()
tests = [
         # ([1,2,3,4,5,6,7],  22, 3, 0),\
         # ([1,2,3,4,5,6,7],  11, 3, 2),\
         # ([1,2,3,4,5,6,7], 7, 3, 5),\
         # ([1,2,3,4,5,6,7],  22, 4, 1),\
         ([-1,1,-1,1,-1,1,-1,1], 0, 1, 0),\
         # ([-1,1,-1,1,-1,1,-1,1], 0, 2, 13),\
         # ([-1,1,-1,1,-1,1,-1,1], 0, None, 16),\
        ]
for nums, target, k, expected in tests:
    ans = sol.subarraySum(nums, target, k)
    print(nums)
    print(ans, ":",expected)

    assert(ans == expected)

'''
[1,3,6,10,15,21,28]

[1,3,6] - offset  = 0 - 1,3,6
[2,5,9] - offset  = 1 - 3,6,10 - got 1
[3,7,12] - offset  = 3 - 6,10,15, - got 3
[4,9,15] - offset  = 6 - 10,15,21 - got 2
[5,11,18] - offset  = 10 - 15,21,28
[6,13] - offset  = 15 - 21,28
[7] - offset  = 21 - 28

[1,3,6,10] - offset  = 0 - 1,3,6,10
[2,5,9,14]- offset  = 1 - 3,6,10,15 - got 1
[3,7,12,18]- offset  = 3 - 6,10,15,21 - got 3
[4,9,15,22]- offset  = 6 - 10,15,21,28 - got 2

'''