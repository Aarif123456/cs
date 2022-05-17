class Solution:
    def trap(self, heights: List[int]) -> int:
        ans, l, r = 0, 0, len(heights)-1
        lMax, rMax = 0, 0
        while l < r:
            if heights[l] < heights[r]:
                if heights[l] >= lMax:
                    lMax = heights[l]
                else:
                    ans += lMax - heights[l]
                l += 1
            else:
                if heights[r] >= rMax:
                    rMax = heights[r]
                else:
                    ans += rMax - heights[r]
                r -= 1
        return ans
