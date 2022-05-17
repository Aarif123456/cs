class Solution {
public:
    /* Using negative to distinguish answer from  k is not good practice */
    bool isAns(int n){
        return n <= 0;
    }
    int helper(TreeNode* root, int k){
        if (root == nullptr) return k;
        k = helper(root->left, k); /* Either k or ans ans*/
        if(isAns(k)) return k;
        k--;
        if (isAns(k)) return -root->val;
        k = helper(root->right, k); /* Either k or ans ans*/
        if(k <= 0) return k;
        assert(k>0);
        return k;
    }
    int kthSmallest(TreeNode* root, int k) {
        return -helper(root, k);
    }
};