# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = 
from queue import SimpleQueue
class Solution:

    def verticalOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        def getLeftmost(root, x = 0):
            if not root: return x
            return min(getLeftmost(root.left, x-1), getLeftmost(root.right, x+1))

        if not root: return []
        offset = -getLeftmost(root)
        q = SimpleQueue()
        q.put_nowait((root, offset-1))
        ans = [[] for _ in range(offset)]
        while not q.empty():
            cur, x = q.get_nowait()
            if len(ans) <= x: 
                ans.append([])
            ans[x].append(cur.val)
            if cur.left: q.put_nowait((cur.left, x-1))
            if cur.right: q.put_nowait((cur.right, x+1))

        return ans
