class Solution:
    def minRemoveToMakeValid(self, s: str) -> str:
        stack = []
        n = len(s)
        valid = [False] * n 
        brackets = {"(", ")"}
        for i,c in enumerate(s):
            if c == "(":
                stack.append(i) 
            elif c == ")":
               if len(stack) > 0: # if we found matching pair
                    valid[i] = True
                    valid[stack.pop()] = True
            else:
                valid[i] = True
        out = ""
        for i, c in enumerate(s):
            if valid[i]: 
                out += c

        return out


'''
    1. We can use a stack to validate a parenthesis
    2. If we know what parenthesis are valid then we can just add those in - we can track valid character with boolean array

    IsValid
    If left bracket - potentially valid till we find match
    - right bracket invalid unless we have match
'''