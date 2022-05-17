/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> parents;

    void makeParents(TreeNode* root, TreeNode* par = nullptr){
        if(!root) return;
        parents[root] = par;
        makeParents(root->left, root);
        makeParents(root->right, root);
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        if(!root || !target) return vector<int>();

        /* make parents */
        parents.clear();
        makeParents(root);

        /* Normal bfs*/
        unordered_set<TreeNode*> visited;
        queue<pair<TreeNode*,int>> next;
        vector<int> out;

        next.push(make_pair(target, 0));
        while(!next.empty()){
            auto p = next.front(); next.pop();
            auto cur = p.first;
            int dist = p.second;
            if(!cur || visited.find(cur) != visited.end() || dist > k) continue;
            visited.insert(cur);
            if(dist == k) {
                out.push_back(cur->val);
            }
            else{
                next.push(make_pair(parents[cur], dist+1));
                next.push(make_pair(cur->left, dist+1));
                next.push(make_pair(cur->right, dist+1));
            }

        }

        return out;
    }
};