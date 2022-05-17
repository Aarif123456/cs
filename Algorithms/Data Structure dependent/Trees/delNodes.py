# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def delNodes(self, root: TreeNode, to_delete: List[int]) -> List[TreeNode]:
        def deleteAndAdd(root, to_delete: set, out: list):
            if not root: return None
            root.left = deleteAndAdd(root.left, to_delete, out)
            root.right = deleteAndAdd(root.right, to_delete, out)
            if root.val in to_delete:
                if root.left:
                    out.append(root.left)
                if root.right:
                    out.append(root.right)
                return None
            return root

        out = []
        to_delete = set(to_delete)

        root = deleteAndAdd(root, to_delete, out)
        if root is not None:
            out.append(root)

        return out


        