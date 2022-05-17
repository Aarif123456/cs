/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param root: a TreeNode
     * @return: a list of integer
     */
    vector<int> boundaryOfBinaryTree(TreeNode * root) {
        vector<int> out;
        if(root != nullptr) {
            out.push_back(root->val);
            collectLeavesAndLeftBondary(root->left, true, out);
            collectLeavesAndRightBondary(root->right, true, out);
        }
        return out;
    }

    bool isLeaf(TreeNode * root){
        return root != nullptr && root->left == nullptr && root->right == nullptr;
    }

    void collectLeavesAndLeftBondary(TreeNode * root, bool isBoundary, vector<int>& out){
        if(root == nullptr) return;
        if(isLeaf(root) || isBoundary) out.push_back(root->val);
        collectLeavesAndLeftBondary(root->left, isBoundary, out);
        collectLeavesAndLeftBondary(root->right, isBoundary && root->left ==nullptr, out);
    }

    void collectLeavesAndRightBondary(TreeNode * root, bool isBoundary, vector<int>& out){
        if(root == nullptr) return;
        collectLeavesAndRightBondary(root->left, isBoundary && root->right ==nullptr, out);
        collectLeavesAndRightBondary(root->right, isBoundary, out);
        /* We add afterwards - so we don't add the right side first */
        if(isLeaf(root) || isBoundary) out.push_back(root->val);
    }
};