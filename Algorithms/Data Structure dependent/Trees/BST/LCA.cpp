/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p->val > q->val) return lowestCommonAncestor(root, q, p);
        if(p->val == q->val) return p;
        if(q->val < root->val) return lowestCommonAncestor(root->left, q, p);
        if(p->val > root->val) return lowestCommonAncestor(root->right, q, p);
        return root;
    }
};