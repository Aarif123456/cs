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
    int ans = 0;

    int helper(TreeNode* root){
        if(root == nullptr) return 0;
        auto maxLeft = helper(root->left), maxRight = helper(root->right);

        ans = max(ans, maxLeft+maxRight);
        return max(maxLeft, maxRight) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans = INT_MIN;
        helper(root);
        return ans;

    }
};