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
    int helper(TreeNode* root, string& cur){
        if(root == nullptr) return 0;
        if(root->left == nullptr && root->right == nullptr) return stoi(cur+to_string(root->val));
        cur.push_back('0'+root->val);
        auto leftSum = helper(root->left, cur);
        auto rightSum = helper(root->right, cur);
        cur.pop_back();

        return leftSum + rightSum;
    }
    int sumNumbers(TreeNode* root) {
        string cur = "0";
        
        return helper(root, cur);
    }
};