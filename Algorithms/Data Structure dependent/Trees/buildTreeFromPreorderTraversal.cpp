class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderMap;
        int n = inorder.size();
        for (int i = 0; i < n; i++) {
            inorderMap[inorder[i]] = i;
        }
        return buildTree(preorder, inorderMap, n, 0);
    }

    /* Parameter
     * size = number of total nodes in current tree
     * cur = The index of current node in the pre-order list
     * leftMost = The index of the leftMost node  in the pre-order
     */
    TreeNode* buildTree(vector<int>& preorder, unordered_map<int, int>& inorder, int size, int cur, int leftMost = 0) {    
        if(size <= 0) return nullptr;
        int val = preorder[cur];
        /* Position in inorder traversal */
        int pos = inorder[val];
        /* Left subtree includes all nodes from leftMost to current node */
        int leftSize = pos - leftMost;
        /* Right subtree must make up leftover nodes */
        int rightSize = size - leftSize - 1; 
        auto left = buildTree(preorder, inorder, leftSize, cur + 1, leftMost);
        auto right = buildTree(preorder, inorder, rightSize, cur + 1 + leftSize, pos+ 1);

        return new TreeNode(val, left, right);
    }
};