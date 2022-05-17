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
    public TreeNode sortedArrayToBST(int[] nums, int l, int r) {
        int m = (l+r)/2;
        TreeNode cur = new TreeNode(nums[m]);
        if(m!=l){
            cur.left = sortedArrayToBST(nums, l, m-1);
        } 
        if(m!=r){
            cur.right = sortedArrayToBST(nums, m+1, r);
        } 
        return cur;
    }
    public TreeNode sortedArrayToBST(int[] nums) {
        if(nums.length == 0) return null;
        return sortedArrayToBST(nums, 0, nums.length-1);
    }
}