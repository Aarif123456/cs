/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */

class Solution {
public:
    int offSet;
    /**
     * @param root: the root of tree
     * @return: the vertical order traversal
     */
    int getLeftMost(TreeNode * root, int x=0){
        if(!root)return std::max(x-1, offSet);
        return max(getLeftMost(root->left, x+1),  getLeftMost(root->right, x-1));
    }

    vector<vector<int>> verticalOrder(TreeNode * root) {
        if(!root) return vector<vector<int>>();
        int offSet =  getLeftMost(root);
        vector<vector<int>> out(offSet+1, vector<int>());
        std::queue< pair<TreeNode*, int>> q;
        q.push(make_pair(root, offSet));
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            auto curNode = cur.first;
            int x = cur.second;
            while(x >= out.size()) out.push_back({});
            out[x].push_back(curNode->val);
            if(curNode->left) q.push(make_pair(curNode->left, x-1));
            if(curNode->right) q.push(make_pair(curNode->right, x+1));
        }
        return out;
    }
};