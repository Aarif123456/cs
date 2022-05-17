# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def closestValue(self, root: Optional[TreeNode], target: float) -> int:
        closest  = float("inf")
        def find(root):
            nonlocal closest, target
            if not root: return
            if abs(root.val-target) < abs(closest-target):
                closest = root.val
            if root.val < target: find(root.right)
            else:  find(root.left)

        find(root)
        return closest
