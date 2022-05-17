/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            auto cur = q.front(); q.pop();
            if(cur == nullptr) continue;
            if(cur->left != nullptr) cur->left->next = cur->right;
            if(cur->right != nullptr && cur->next != nullptr) cur->right->next = cur->next->left;
            q.push(cur->left);
            q.push(cur->right);
        }

        return root;
    }
};