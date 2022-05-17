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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> out;
        deque<TreeNode*> next;
        bool even = true;
        if(root) next.push_front(root);
        while(!next.empty()){
            int size = next.size();
            out.push_back(vector<int>());
            for(int i = 0; i < size; i++){
                if(even){
                    auto cur = next.front(); next.pop_front();
                    out.back().push_back(cur->val);
                    if(cur->left) next.push_back(cur->left);
                    if(cur->right) next.push_back(cur->right);
                }
                else{
                    auto cur = next.back(); next.pop_back();
                    out.back().push_back(cur->val);
                    if(cur->right) next.push_front(cur->right);
                    if(cur->left) next.push_front(cur->left);
                }
            }
            even = !even;
        }

        return out;
    }
};