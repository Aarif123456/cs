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
    vector<int> inorderTraversal(TreeNode* root) {
        std::vector<int> out;
        std::stack<TreeNode*> stack;
        TreeNode* cur = root;
        while(!stack.empty() || cur){
            if(cur){ /* Go left as far as we can */
                stack.push(cur);
                cur = cur->left;
            }
            else{ /* If we can't go left we record and try to go right */
                cur = stack.top(); stack.pop();
                out.push_back(cur->val);
                cur = cur->right;
            }
        }
        return out;
    }
};