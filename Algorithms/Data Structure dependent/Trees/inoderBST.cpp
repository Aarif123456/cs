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
    
    TreeNode * getLeftMost(TreeNode * root){
        while(root->left != nullptr) root = root->left;
        return root;
    }
    /*
     * @param root: The root of the BST.
     * @param p: You need find the successor node of p.
     * @return: Successor of p.
     */
    TreeNode * inorderSuccessor(TreeNode * root, TreeNode * p) {
        if(root == nullptr || p == nullptr) return nullptr;

        if(p->right != nullptr) return getLeftMost(p->right);
        auto cur = root;
        TreeNode* ans = nullptr;
        while(cur != p){
            if(cur->val >= p->val){
                if(ans == nullptr || cur->val < ans->val) ans = cur;
                cur = cur->left;
            } 
            else{
                cur = cur->right;
            }
        }
        return ans;
    }
};