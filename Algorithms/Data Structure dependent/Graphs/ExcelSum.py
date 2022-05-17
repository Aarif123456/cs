from functools import partial
from collections import defaultdict

# Class to force pass by reference
class Node:
    def __init__(self, val = 0):
        self.val = val
    def __repr__(self)->str:
        return str(self.val)

class Excel:
    def __init__(self, height: int, width: str):
        # each rule maps to a list of lambdas that execute if rule is valid
        self.rulesMap = [defaultdict(list) for i in range(height+1)]
        # our grid
        self.nodes = [defaultdict(Node) for i in range(height+1)]

    # set value and propagate to dependent nodes  
    # O(k) - where k is number of rules
    def _changeVal(self, row: int, col: str, val: int)->None:
        oldVal = self.nodes[row][col].val
        self.nodes[row][col].val = val
        delta = val - oldVal
        for ruleRows in self.rulesMap:
            for rules in ruleRows.values():
                for rule in rules:
                    rule(row, col, delta)

    # helper function that check for rules with ranges e.g. A1:B12
    def _rangedRule(self, row, col, topLeft, bottomRight, x, y, deltaVal):
        node = self.nodes[row][col]
        x1, y1 = topLeft
        x2, y2 = bottomRight
        if x >= x1 and x <= x2 and y >= y1 and y <= y2:
            self.add(row, col, deltaVal)

    # helper function that checks if the cell is a target of any rules
    def _cellRule(self, row, col, target, x, y, deltaVal):
        node = self.nodes[row][col]
        targX, targY = target 
        if x == targX and y == targY:
            self.add(row, col, deltaVal)

    # set function that deletes any current sum rules and sets new value
    def set(self, row: int, col: str, val: int) -> None:
        self.rulesMap[row][col] = []
        self._changeVal(row, col, val)

    # add new value to cell
    def add(self, row: int, col: str, val: int):
        oldVal = self.nodes[row][col].val
        self._changeVal(row, col, self.nodes[row][col].val  + val)

    # get value of current cell - O(1)
    def get(self, row: int, col: str) -> int:
        return self.nodes[row][col].val

    # Function to set sum rule to a cell 
    # O(n) - where n is number of cells affected by rule
    def sum(self, row: int, col: str, numbers: list) -> int:
        node = self.nodes[row][col]
        self.rulesMap[row][col] = []
        rowsToCheck = []
        for ruleTarget in numbers:
            # ranged rules are in the form CX:KY - where X and Y are integers
            vals = ruleTarget.split(":")
            # handle single-cell sum rule
            if len(vals) == 1:
                target = int(ruleTarget[1:]), ruleTarget[0]
                self.rulesMap[row][col].append(partial(self._cellRule, row, col, target))
                rowsToCheck.append(target)
            # handle ranged sum rule
            elif len(vals) == 2:
                y1, x1 = vals[0][0], int(vals[0][1:])
                y2, x2 = vals[1][0], int(vals[1][1:])
                topLeft =  x1, y1
                bottomRight = x2 , y2
                self.rulesMap[row][col].append(partial(self._rangedRule, row, col, topLeft, bottomRight))

                yr1, yr2 = ord(y1), ord(y2)
                for x in range(x1, x2+1):
                    for y in range(yr1, yr2+1):
                        rowsToCheck.append((int(x),chr(y)))
        # calculate sum are propagate value if necessary
        self._changeVal(row, col, sum([self.nodes[x][y].val for x,y in rowsToCheck]))

        return node.val
