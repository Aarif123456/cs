"""
# Definition for Employee.
class Employee:
    def __init__(self, id: int, importance: int, subordinates: List[int]):
        self.id = id
        self.importance = importance
        self.subordinates = subordinates
"""

class Solution:
    def getImportance(self, employees: List['Employee'], id: int) -> int:
        importance, employeeGraph = {}, {}
        for employee in employees:
            employeeGraph[employee.id] = employee

        def dfs(eId):
            nonlocal importance, employeeGraph
            if eId in importance:
                return importance[eId]
            imp = employeeGraph[eId].importance
            for subId in employeeGraph[eId].subordinates:
                imp += dfs(subId)

            return imp

        return dfs(id)
        # employees.sort(key = lambda a: len(a.subordinates))

