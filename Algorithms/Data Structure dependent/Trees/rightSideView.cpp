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
    void helper(TreeNode* root, vector<int>&out, int depth){
        if(root == nullptr) return;
        if(depth >= out.size()) out.push_back(root->val);
        helper(root->right, out, depth+1);
        helper(root->left, out, depth+1);
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<int> out;
        helper(root, out, 0);

        return out;
    }
};