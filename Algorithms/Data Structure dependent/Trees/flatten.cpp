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
    void helper(TreeNode* root, TreeNode* ans){
        if (root == nullptr) return;
        TreeNode cur(root->val);
        ans->right = &cur;
        ans = ans->right;
        cout << ans->val << ",";
        helper(root->left, ans);
        helper(root->right, ans);
    }
    
    void flatten(TreeNode* root) {
        TreeNode start(-1);
        helper(root, &start);
        auto next = start.right;
        root->left = nullptr;
        root->right = next->right;
    }
};