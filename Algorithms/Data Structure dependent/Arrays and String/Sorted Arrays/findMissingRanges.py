class Solution:
    def findMissingRanges(self, nums: List[int], lower: int, upper: int) -> List[str]:
        out = []
        nums =[x for x in nums if x >= lower and x <= upper]
        nums = [lower-1] + nums + [upper+1]
        for i,x in enumerate(nums):
            if i == 0 or x < lower: continue
            if x > upper+1: break
            dif = x - nums[i-1]
            if dif < 2: continue
            if dif == 2:
                out.append(str(x-1))
            else:
                out.append(f"{nums[i-1]+1}->{x-1}")

        return out

        