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
    /* Find min - if min has a right-tree swap root with it's smallest value in right */
    TreeNode* findMin(TreeNode* root){
        if(!root) return nullptr;
        while(root->left) root = root->left;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;
        /* If key smaller search left */
        if(root->val > key) root->left = deleteNode(root->left, key);
        /* if key bigger go to right */
        if(root->val < key) root->right = deleteNode(root->right, key);
        /* If root will not be deleted then we are done*/
        if(root->val != key) return root;
        
        /* Handle 0 or 1 child case */
        if(!root->left) return root->right;
        if(!root->right) return root->left;

        /* If both child recursively replace value with lowest value in right subtree */
        auto min = findMin(root->right);
        root->val = min->val;
        root->right = deleteNode(root->right, min->val);
        return root;
    }
};