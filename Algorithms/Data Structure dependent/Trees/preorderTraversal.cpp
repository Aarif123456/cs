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
    /* Inorder: left => cur => right - print
     * Preorder: cur => left => right - copy
     * Postorder: left => right => cur - delete
     */
    vector<int> preorderTraversal(TreeNode* root) {
        std::vector<int> out;
        std::stack<TreeNode*> stack;
        stack.push(root);
        while(!stack.empty()){
            auto cur = stack.top(); stack.pop();
            if(cur == nullptr) continue;
            out.push_back(cur->val);
            stack.push(cur->right);
            stack.push(cur->left);
        }
        return out;
    }
};