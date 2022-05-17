# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findLeaves(self, root: Optional[TreeNode]) -> List[List[int]]:
        def helper(root):
            nonlocal out
            if root is None: return -1

            left = helper(root.left)
            right = helper(root.right)
            curLevel = max(left, right)+1
            if curLevel >= len(out):
                out.append([])
            out[curLevel].append(root.val)
            return curLevel

        out = []
        helper(root)
        return out
