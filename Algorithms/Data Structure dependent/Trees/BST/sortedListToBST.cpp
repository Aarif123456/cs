/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    int getSize(ListNode* head){
        int size = 0;
        while(head != nullptr) {
            head = head->next;
            size++;
        }

        return size;
    }

    TreeNode* sortedListToBST(ListNode* head, int size){
        if(size <= 0 || head == nullptr) return nullptr;
        int mid = size/2;
        auto cur = head;
        for (int i = 0; i < mid; i++) cur = cur->next;
        auto root = new TreeNode(cur->val);
        root->left = sortedListToBST(head, mid);
        root->right = sortedListToBST(cur->next, size-mid-1);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int size = getSize(head);
        return sortedListToBST(head, size);
    }
};