/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Status{
    int targetFound;
    TreeNode* LCA;
};

class Solution {
public:
    Status helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr) return {0, nullptr};
        int numTarget = 0;
        if (root == p) numTarget++;
        if (root == q) numTarget++;

        auto right = helper(root->right, p, q);
        if(right.LCA != nullptr) return right;
        auto left = helper(root->left, p, q);
        if(left.LCA != nullptr) return left;

        numTarget += right.targetFound + left.targetFound;
        return {numTarget, numTarget == 2 ? root : nullptr};
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode* LCA = nullptr) {
        return helper(root, p, q).LCA;
    }
};