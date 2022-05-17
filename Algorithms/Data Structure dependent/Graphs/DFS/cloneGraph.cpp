/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        std::unordered_map<Node*, Node*> mapper;
        std::stack<Node*> next;
        std::unordered_set<Node*> visited;
        if(node) next.push(node);
        while(!next.empty()){
            auto cur = next.top(); next.pop();
            if(visited.find(cur) != visited.end()) continue;
            if(!mapper[cur]) mapper[cur] = new Node(cur->val);
            visited.insert(cur);
            for(auto neighbor: cur->neighbors){
                if(!mapper[neighbor]) {
                    mapper[neighbor] = new Node(neighbor->val);
                    /* If we don't have a map we haven't seen the node 
                    */
                    next.push(neighbor);
                }
                mapper[cur]->neighbors.push_back(mapper[neighbor]);
            }
        }

        return mapper[node];
    } 
};