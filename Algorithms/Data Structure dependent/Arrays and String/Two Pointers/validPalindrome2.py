class Solution:
    def validPalindrome(self, s: str) -> bool:
        def helper(s: str, k: int, l: int, r: int):
            while l < r:
                if s[l] != s[r]:
                    if k: return helper(s, k-1, l+1, r) or helper(s, k-1, l, r-1)
                    return False

                l+=1
                r-=1

            return True

        s = list(s)
        return helper(s, 1, 0, len(s)-1)