typedef long long ll;
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
    bool isValidBST(TreeNode* root, int * min = nullptr, int * max = nullptr) {
        if(root == nullptr) return true;
        int val = root->val;
        if((max && val >= *max) || (min && val <= *min)) return false;
        return isValidBST(root->left, min, &val) &&  isValidBST(root->right, &val, max);
    }
};