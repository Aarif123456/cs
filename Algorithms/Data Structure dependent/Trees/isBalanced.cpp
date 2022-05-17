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
    bool isLeaf(TreeNode* cur){
        return cur->left == nullptr && cur->right == nullptr;
    }
    bool isBalanced(TreeNode* root) {
        if(root == nullptr || isLeaf(root)) return true;
        queue<TreeNode> levels;
        int curLevel=0, firstLeaf=INT_MAX;
        levels.push(*root);
        while(!levels.empty()){
            queue<TreeNode> next;
            while(!levels.empty()){
                auto cur = levels.front();
                levels.pop();
                if(cur.left != nullptr) next.push(*cur.left);
                if(cur.right != nullptr) next.push(*cur.right);
                if(isLeaf(&cur)){
                    firstLeaf = min(firstLeaf, curLevel);
                    if(curLevel-firstLeaf>1) return false;
                }
            }
            curLevel += 1;
            levels=next;
        }

        return curLevel-firstLeaf<=1;
    }
};