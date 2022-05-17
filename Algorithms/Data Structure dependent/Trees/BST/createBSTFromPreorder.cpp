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
    int numNode = 0;
    TreeNode* helper(vector<int>& preorder, int* max = nullptr ){
        if(numNode < 0 || numNode >= preorder.size()) return nullptr;
        if(max && preorder[numNode] > *max) return nullptr;
        TreeNode* root = new TreeNode(preorder[numNode]);
        numNode++;
        root->left = helper(preorder, &root->val);
        root->right = helper(preorder, max);
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        numNode = 0;
        return helper(preorder);
    }
};