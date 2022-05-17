/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func helper(root *TreeNode, isLeft bool) int{
    if root == nil {
        return 0
    }
    if root.Left == nil && root.Right == nil && isLeft {
        return root.Val
    }

    lSum, rSum := helper(root.Left, true), helper(root.Right, false)

    return lSum + rSum
}

func sumOfLeftLeaves(root *TreeNode) int {
    return helper(root, false)
}