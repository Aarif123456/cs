/**
 * Definition for a Node.
 * type Node struct {
 *     Val int
 *     Prev *Node
 *     Next *Node
 *     Child *Node
 * }
 */
func helper(root *Node) *Node {
    if root == nil || (root.Child == nil && root.Next == nil){
        return root
    }
    if root.Child != nil {
        tmp := root.Next
        root.Next = root.Child
        /* Get last node from flattened list and set their next to our old next*/
        lastChild := helper(root.Child)
        root.Child = nil
        lastChild.Next = tmp
        helper(lastChild)
    }

    return helper(root.Next)
}
func flatten(root *Node) *Node {
    helper(root)
    prev := (*Node)(nil)
    cur := root
    for cur != (*Node)(nil) {
        cur.Prev = prev
        prev = cur
        cur = cur.Next
    }
    return root
}