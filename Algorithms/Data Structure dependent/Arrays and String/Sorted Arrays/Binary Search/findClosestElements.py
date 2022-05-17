class Solution:
    def findClosestElements(self, arr: List[int], k: int, x: int) -> List[int]:
        l, r = 0, len(arr)-k
        while l < r:
            m = (l+r)//2
            # this is our midpoint - now if the value is bigger than our midpoint it's too big
            if x > (arr[m]+arr[m+k])/2 :
                l=m+1
            else:
                r=m
        return arr[l: l+k]