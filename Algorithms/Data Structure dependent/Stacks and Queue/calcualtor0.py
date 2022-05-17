def applyFunc(stack, target, func):
    appliedFunc = [stack[0]]
    for i in range(1,len(stack)):
        if stack[i-1] == target:
            appliedFunc.pop()
            a,b = appliedFunc.pop(), stack[i]
            appliedFunc.append(func(a,b))
        else:
            appliedFunc.append(stack[i])
    return appliedFunc

def convertToStack(s):
    num = ""
    numberMode = True
    stack = []
    for c in s:
        if numberMode:
            if (not num and c in {"+", "-"}) or c.isdigit():
                num += c
            else:
                stack.append(int(num))
                numberMode = False
                num = ""
        if not numberMode:
            stack.append(c)
            numberMode = True
    stack.append(int(num))

    return stack

class Solution:
    def solve(self, s):
        if not s: return 0
        # Convert to stack - similar to RPN notation
        stack = convertToStack(s)
        multiply = applyFunc(stack, "*", lambda a,b: a*b)
        divide = applyFunc(multiply, "/", lambda a,b: math.floor(a/b))
        sub = applyFunc(divide, "-", lambda a,b: a-b)
        add = applyFunc(sub, "+", lambda a,b: a+b)

        return add[0]