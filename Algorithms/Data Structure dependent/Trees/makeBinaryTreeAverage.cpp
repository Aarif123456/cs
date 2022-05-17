/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /* At each step we have 4 possible moves
     * 1. Change current value to average of two kids - no extra moves
     * 2. Change left child to a value to reach average - might need to reshuffle 
     * 3. Change right child to a value to reach average
     * 4. Do nothing 
    */
    int makeBinaryTreeAverage(TreeNode * root) {
        
    }
};