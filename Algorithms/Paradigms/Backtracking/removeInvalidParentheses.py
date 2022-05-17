from queue import SimpleQueue
class Solution:
    # 1.make sure result is valid
    # 2.remove min parenthesis
    # 3.only create unique string
    def removeInvalidParentheses(self, s: str) -> List[str]:
        def isValid(s):
            count = 0
            for c in s:
                if c == "(": count += 1
                elif c == ")":
                    if count: count -= 1
                    else: return False

            return not count
        nxt = SimpleQueue()
        nxt.put_nowait((s, 0))
        ans = []
        while not nxt.empty():
            ss,steps = nxt.get_nowait()
            if isValid(ss): ans.append(ss)
            elif len(ans) == 0:
                for i in range(steps, len(ss)):
                    if((ss[i]==')'or ss[i]=='(') and (i==steps or ss[i]!=ss[i-1])): 
                        nxt.put_nowait((ss[:i]+ss[i+1:], i))

        return ans
        