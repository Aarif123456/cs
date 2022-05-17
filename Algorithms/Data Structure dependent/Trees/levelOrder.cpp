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
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
class Solution {
public:
    void helper(TreeNode* root, vvi& out, int level = 0){
        if(!root) return;
        if(out.size() <= level) out.push_back(vi());
        out[level].push_back(root->val);
        helper(root->left, out, level+1);
        helper(root->right, out, level+1);
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        vvi out;
        helper(root, out, 0);
        return out;
    }
};