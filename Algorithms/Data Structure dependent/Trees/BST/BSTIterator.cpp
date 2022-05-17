class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        cur = root;
    }

    int next() {
        assert(hasNext());
        auto nextNode = getNext();
        return nextNode->val;
    }
    
    bool hasNext() {
        return !stack.empty() || cur;
    }
    
private:
    TreeNode* cur;
    std::stack<TreeNode*> stack;

    TreeNode* getNext(){
        /* Go left as far as we can */
        while(cur != nullptr){
            stack.push(cur);
            cur = cur->left;
        }
        /* After we process current node - we try to go right subtree */
        TreeNode* next = stack.top(); stack.pop();
        cur = next->right;

        return next;
    }
};

