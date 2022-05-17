/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */


class Solution {
public:
    /* 1. Node has right subtree - just find left most
     * 2. Otherwise find the node that points from the left
     */
    TreeNode * findLeftmost(TreeNode * root){
        while(root->left != nullptr) root = root->left;
        return root;
    }
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p, TreeNode * ans  = nullptr) {
        if(root == nullptr || p == nullptr) return nullptr;
        if(p->right != nullptr) return findLeftmost(p->right);
        if(root == p) return ans;
        if(root->val >= p->val){
            if(ans == nullptr ||root->val < ans->val) ans = root;
            return inorderSuccessor(root->left, p, ans);
        }
        
        return inorderSuccessor(root->right, p, ans);
    }
};