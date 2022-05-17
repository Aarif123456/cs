/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    int getDepth(Node* cur){
        int depth = 0;
        while(cur != nullptr){
            cur = cur->parent;
            depth++;
        }

        return depth;
    }

    Node* lowestCommonAncestor(Node* p, Node * q) {
        int d1 = getDepth(p), d2 = getDepth(q);
        while(d1 > d2){
            p = p->parent;
            d1--;
        }
        while(d2 > d1){
            q = q->parent;
            d2--;
        }

        while(p != q){
            p = p->parent;
            q = q->parent;
        }

        return p;
    }
};