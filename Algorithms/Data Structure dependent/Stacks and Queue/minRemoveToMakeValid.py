class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        closeCount = 0

        for c in s:
            if c == ')': closeCount += 1

        openMatchedCount = 0
        out = ""

        for c in s:
            if c == ')':
                closeCount -= 1
                if not openMatchedCount: continue
                openMatchedCount -= 1
            elif c == '(':
                if openMatchedCount == closeCount: continue
                openMatchedCount += 1
            out += c 

        return out