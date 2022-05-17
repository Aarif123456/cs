
class Solution {
public:
    Node* prev;
    Node* head;

    void helper(Node* root){
        if(!root) return;
        helper(root->left);
        auto next = root->right;

        root->left = prev;
        if(prev) prev->right = root;

        if(!head || root->val < head->val) head = root;
        prev = root;

        helper(next);
    }

    Node* treeToDoublyList(Node* root){
        if(!root) return nullptr;
        prev = nullptr; head = nullptr;

        helper(root);

        head->left = prev;
        if(prev) prev->right = head;

        return head;
    }
};