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
    void collectLeaves(list<int>& leaves, TreeNode* root){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr){
            leaves.push_back(root->val);
        }
        else{
            collectLeaves(leaves, root->left);
            collectLeaves(leaves, root->right);
        }
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        list<int> leaves1, leaves2;
        collectLeaves(leaves1, root1);
        collectLeaves(leaves2, root2);

        return leaves1 == leaves2;
    }
};