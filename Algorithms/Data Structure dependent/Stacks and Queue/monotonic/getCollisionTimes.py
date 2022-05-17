class Solution:
    def getCollisionTimes(self, cars: List[List[int]]) -> List[float]:
        reverse_enumerate = lambda l: zip(range(len(l)-1, -1, -1), reversed(l))

        n = len(cars)
        stack = []
        out = [float("inf")] * n

        for i, (p1, s1) in reverse_enumerate(cars):
            p2, s2 = cars[stack[-1]] if stack else (-1, -1)

            # if collision happens earlier or speed is faster get rid of it
            while stack and (cars[stack[-1]][1] >= s1 \
                or out[stack[-1]] < ((p2-p1)/(s1-s2)) ):
                stack.pop()
                p2, s2 = cars[stack[-1]] if stack else (-1, -1)
            if stack:
                out[i] = ((p2-p1)/(s1-s2))
            stack.append(i)

        return [x if not math.isinf(x) else -1 for x in out ]