/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if(root==null) return new ArrayList<>();
        Deque<TreeNode> levelNodes = new ArrayDeque<>();
        List<List<Integer>> out = new ArrayList<>();
        levelNodes.offerFirst(root);
        boolean right=false;
        while(levelNodes.size()>0){
            List<Integer> curLevel =  new ArrayList<>();
            int numNodes = levelNodes.size();
            for(int i=0; i<numNodes; i++){
                if(right){
                    TreeNode cur = levelNodes.pollLast();
                    curLevel.add(cur.val);
                    if(cur.right != null) levelNodes.offerFirst(cur.right);
                    if(cur.left != null) levelNodes.offerFirst(cur.left);
                }
                else{
                    TreeNode cur = levelNodes.pollFirst();
                    curLevel.add(cur.val);
                    if(cur.left != null) levelNodes.offerLast(cur.left);
                    if(cur.right != null) levelNodes.offerLast(cur.right);
                }
            }
            right = !right;
            out.add(curLevel);
        }

        return out;
    }
}