/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
 import (
    "fmt"
    "math"
)
func countNodes(root *TreeNode) int {
    if root == nil{
        return 0
    }
    lh, rh := 0, 0
    left, right := root.Left, root.Right
    for left != nil{
        left = left.Left
        lh++
    }

    for right != nil{
        right = right.Right
        rh++
    }

    if lh == rh{
        return int(math.Pow(2., float64(lh+1)))-1
    }

    return 1 + countNodes(root.Left) + countNodes(root.Right)

}