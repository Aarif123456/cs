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
    void helper(TreeNode* root, vector<int>& out, int depth=0){
        if(!root) return;
        if(out.size() <= depth) out.push_back(root->val);
        else out[depth] = std::max(out[depth], root->val);
        helper(root->left, out, depth+1);
        helper(root->right, out, depth+1);
    }

    vector<int> largestValues(TreeNode* root) {
        vector<int> out;
        helper(root, out);
        return out;
    }
};