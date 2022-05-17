class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        positives, ans = [], []
        for a in asteroids:
            if a>0:
                positives.append(a)
            else:
                while positives and positives[-1] < -a:
                    positives.pop()
                if positives and positives[-1] == -a:
                    positives.pop()
                elif not positives:
                    ans.append(a)


        return ans + positives