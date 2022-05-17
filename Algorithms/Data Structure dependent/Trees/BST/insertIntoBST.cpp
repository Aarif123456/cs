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
    TreeNode* insertIntoBST(TreeNode* root, TreeNode* newNode) {
        if(root == nullptr) return newNode;
        if(root->val > newNode->val) {
            if(root->left == nullptr) root->left = newNode;
            else insertIntoBST(root->left, newNode);
        }
        else{
            if(root->right == nullptr) root->right = newNode;
             else insertIntoBST(root->right, newNode);
        }
        return root;

    }
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return insertIntoBST(root, new TreeNode(val));
    }
};