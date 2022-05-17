/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int lo, int hi) {
        if(!root) return nullptr;
        root->left = trimBST(root->left, lo, hi);
        root->right = trimBST(root->right, lo, hi);
        if(root->val > hi) return root->left;
        if(root->val < lo) return root->right;
        return root;
    }
};