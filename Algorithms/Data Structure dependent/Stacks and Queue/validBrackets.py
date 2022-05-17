class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        openParenthesis = {'(', '{', '['}
        closedParenthesis = {')', '}', ']'}
        for c in s:
            if c in openParenthesis:
                stack.append(c)
            elif c in closedParenthesis:
                if not stack: 
                    return False
                match = stack.pop()
                if (match == '(' and c != ')') or \
                    (match == '{' and c != '}') or \
                    (match == '[' and c != ']'):
                    return False

        return not stack

