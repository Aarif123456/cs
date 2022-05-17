# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class BSTIterator:
    cur = None
    stack = []

    def __init__(self, root: Optional[TreeNode]):
        self.cur = root
        self.stack = []

    def next(self) -> int:
        self.pushLeft()
        nextNode = self.stack.pop()
        self.cur = nextNode.right

        return nextNode.val

    def hasNext(self) -> bool:
        return self.cur or len(self.stack)

    def pushLeft(self):
        root = self.cur 
        while root:
            self.stack.append(root)
            root = root.left

