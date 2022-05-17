from queue import SimpleQueue
class Solution:
    def removeInvalidParentheses(self, s: str) -> List[str]:
        def helper(s, ans, iStart, jStart, openPar, closePar):
            openCount, closeCount = 0, 0
            for i in range(iStart, len(s)):
                c = s[i]
                if c == openPar: openCount += 1
                elif c == closePar: closeCount += 1
                if closeCount > openCount: break

            # If we have disbalanced string - try to remove all non  
            if closeCount > openCount:
                # i -= 1
                for j in range(jStart, i+1):
                    if s[j] == closePar and (j == jStart or s[j-1] != s[j]):
                        helper(s[:j] + s[j+1:], ans, i, j, openPar, closePar)
            # if valid - reverse and handle open brackets 
            # or go to normal and add
            else:
                rev = s[::-1]
                if openPar == '(':
                    helper(rev, ans, 0, 0, closePar, openPar)
                else:
                    ans.append(rev)

        ans = []
        helper(s, ans, 0, 0, '(', ')')
        return ans