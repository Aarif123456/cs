class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        rev = ""
        closeCount = 0 
        for c in reversed(s):
            if c == ")": 
                closeCount += 1
                rev += c
            elif c == "(": 
                if closeCount > 0:
                    closeCount -= 1
                    rev += c
            else:
                rev += c

        out = ""
        openCount = 0
        for c in reversed(rev):
            if c == "(": 
                openCount += 1
                out += c
            elif c == ")": 
                if openCount > 0:
                    openCount -= 1
                    out += c
            else:
                out += c


        return out
