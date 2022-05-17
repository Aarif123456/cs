# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:

    def maxPathSum(self, root: Optional[TreeNode]) -> int:
        ans = -1001
        def getBest(node):
            nonlocal ans
            if node is None: return 0
            leftSum = getBest(node.left)
            rightSum = getBest(node.right)

            curSum = node.val + leftSum + rightSum
            ans = max(ans, curSum)
            # We can only use one at most branch
            return max(node.val + max(leftSum, rightSum), 0)
        getBest(root)
        return ans
