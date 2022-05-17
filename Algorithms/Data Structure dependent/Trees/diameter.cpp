/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
typedef vector<int> vi;
class Solution {
public:
    int best = 0;
    int helper(Node* root){
        if(!root) return 0;
        priority_queue<int, vi, greater<int>> pq;
        pq.push(0);
        for(auto &child : root->children){
            pq.push(helper(child));
            if(pq.size()>2) pq.pop();
        }
        int curDiameter = 0;
        if(pq.size() > 1){
            curDiameter += pq.top(); pq.pop();
        }
        curDiameter += pq.top();
        best = std::max(best, curDiameter);

        return pq.top()+1;
    }
    int diameter(Node* root) {
       helper(root);
       return best;
    }
};