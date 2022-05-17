struct Status{
    int targetFound;
    TreeNode * ancestor;
};

class Solution {
public:
    /*
     * @param root: The root of the binary tree.
     * @param A: A TreeNode
     * @param B: A TreeNode
     * @return: Return the LCA of the two nodes.
     */
    Status lowestCommonAncestor3(TreeNode * root, unordered_set<TreeNode *>& targets, int numTarget){
        if(!root) return {0, nullptr};
        auto left = lowestCommonAncestor3(root->left, targets, numTarget);
        if(left.targetFound == numTarget) return left;
        auto right = lowestCommonAncestor3(root->right, targets, numTarget);
        if(right.targetFound == numTarget) return right;
        int targetFound = left.targetFound + right.targetFound;
        if(targets.find(root) != targets.end()) targetFound++;

        return {targetFound, targetFound == numTarget ? root : nullptr};

    }

    TreeNode * lowestCommonAncestor3(TreeNode * root, TreeNode * A, TreeNode * B) {
        unordered_set<TreeNode *> targets = {A, B};
        auto status =  lowestCommonAncestor3(root, targets, 2);
        return status.ancestor;
    }
};