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
    const int INVALID = -1;
    int helper(TreeNode* root, int height = 0){
        if(root == nullptr) return height + 1;
        int left = helper(root->left, height);
        if(left == INVALID) return INVALID;
        int right = helper(root->right, height);
        if (right == INVALID) return INVALID;
        return abs(left-right) <= 1 ? max(left, right) + 1 : -1; 

    }
    bool isBalanced(TreeNode* root) {
        return helper(root) != INVALID;
    }
};