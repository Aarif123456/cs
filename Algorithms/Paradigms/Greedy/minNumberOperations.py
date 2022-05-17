class Solution:
    def minNumberOperations(self, target: List[int]) -> int:
        # we use a min to set a baseline - if new element is less change baseline
        # otherwise add cost - and upgrade base line
        lastMin, cost = 0, 0
        for x in target:
            if x <= lastMin:
                lastMin = x
            else:
                cost += x-lastMin
                lastMin = x 

        return cost


