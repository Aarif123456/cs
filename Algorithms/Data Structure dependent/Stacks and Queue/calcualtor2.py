def applyFunc(stack, targets, func):
    # print(stack)
    out = [stack[0]]
    n = len(stack)
    for i in range(1, n):
        c = stack[i]
        if stack[i-1] in targets:
            a,b = out.pop(), c 
            out.append(func(a,b, stack[i-1]))
        elif c not in targets:
            out.append(c)

    return out

def createStack(s:str):
    numberMode = True
    num = ""
    operators = {"+", "-", "*", "/"}
    stack = []
    for c in s:
        if c.isspace(): continue
        if numberMode:
            if num == "" and (c=="+" or c=="-"):
                num += c
            elif c.isdigit():
                num += c
            else:
                if num: stack.append(int(num))
                num = ""
                numberMode = False
        if not numberMode:
            if c in operators:
                stack.append(c)
                numberMode = True
    if num: stack.append(int(num))
    return stack

class Solution:
    def calculate(self, s: str) -> int:
        stack = createStack(s)
        stack = applyFunc(stack, {"/", "*"}, lambda x,y,op: (x//y if x//y >= 0 else x//y+1) if op == "/" else x*y)
        stack = applyFunc(stack, {"-"}, lambda x,y,op: x-y)
        stack = applyFunc(stack, {"+"}, lambda x,y,op: x+y)
        # print(stack)
        assert(len(stack) == 1)
        return stack.pop()