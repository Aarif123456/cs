/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;

    Node() {}

    Node(int _val) {
        val = _val;
        next = NULL;
    }

    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};
*/

class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        Node* node = new Node(insertVal);
        if(!head) {
            node->next = node;
            return node;
        }

        auto smallest = head, biggest = head, prev = head, cur = head->next;
        while(cur != head) {
            if(cur->val <= smallest->val && cur->val != prev->val) smallest = cur;
            if(cur->val >= biggest->val && cur->val != prev->val) biggest = cur;
            prev = cur;
            cur = cur->next;
        }
        /* move biggest right before smallest*/
        while(biggest->next != smallest) biggest = biggest->next;

        if(node->val <= smallest->val || node->val >= biggest->val){
            biggest->next = node;
            node->next = smallest;
        }
        else {
            cur = smallest;
            while( node->val > cur->val)  cur = cur->next;
            auto chaser = smallest;
            while(chaser->next != cur) chaser = chaser->next;
            chaser->next = node;
            node->next = cur;

        }
        
        return head;
    }
};