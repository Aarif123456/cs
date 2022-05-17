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
    TreeNode* convertArray(vector<TreeNode*>& inorder, int l, int r){
        if(r<l) return nullptr;
        int m = (l+r)/2;
        auto root = inorder[m];
        root->left = convertArray(inorder, l, m-1);
        root->right = convertArray(inorder, m+1, r);

        return root;
    }

    vector<TreeNode*> inorderTraversal(TreeNode* root){
        vector<TreeNode*> inorder;
        std::stack<TreeNode*> stk;
        auto cur = root;
        while(cur || !stk.empty()){
            if(cur){
                stk.push(cur);
                cur = cur->left;
            }
            else{
                cur = stk.top(); stk.pop();
                inorder.push_back(cur);
                cur = cur->right;
            }
        }
        return inorder;
    }

    TreeNode* balanceBST(TreeNode* root) {
        auto inorder = inorderTraversal(root);
        return convertArray(inorder, 0, inorder.size()-1);
    }
};