"""
Definition of TreeNode:
class TreeNode:
    def __init__(self, val):
        self.val = val
        self.left, self.right = None, None
"""

class Solution:
    """
    @param s: a string
    @return: a root of this tree
    """
    def str2tree(self, s):
        pos = 0
        def helper(s):
            nonlocal pos
            if pos >= len(s): return None
            bracketed = s[pos] == "(" 
            if bracketed: pos += 1
            num = ""
            while pos < len(s) and (s[pos] == "-" or s[pos].isdigit()): 
                num += s[pos]
                pos += 1
            n = int(num) if num != "" else 0
            root = TreeNode(n)
            if pos < len(s) and s[pos] == "(": root.left = helper(s)
            if pos < len(s) and s[pos] == "(": root.right = helper(s)
            if bracketed and s[pos] == ")": pos += 1
            return root
        return helper(s)
