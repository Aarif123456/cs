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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderMap;
        int n = inorder.size();
        for(int i = 0; i < n; i++) {
            inorderMap[inorder[i]] = i;
        }

        return buildTree(inorderMap, postorder, n, n-1, 0);
    }

    TreeNode* buildTree(unordered_map<int, int>& inorder, vector<int>& postorder, int size, int cur, int leftMost) {
        if(size <= 0) return nullptr;
        int val = postorder[cur];
        /* Inorder position */
        int pos = inorder[val];
        /* Size of left subtree is the number of nodes from current node 
         * to leftMost node
         */
        int leftSize = pos - leftMost;
        /* Remaining nodes must be in the right subtree */
        int rightSize = size - leftSize - 1;
        auto root = new TreeNode(val);
        root->right = buildTree(inorder, postorder, rightSize, cur-1, pos + 1);
        root->left = buildTree(inorder, postorder, leftSize, cur-1-rightSize, leftMost);
;
        return root;
    }
};