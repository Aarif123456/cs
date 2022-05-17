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
    int getLLSize(ListNode* head){
        auto cur = head;
        int size = 0;
        while(cur != nullptr){
            size++; 
            cur = cur->next;
        }
        return size;
    }

    TreeNode* helper(ListNode* node, int l, int r){
        if(node == nullptr || l>r) return nullptr;
        int m = (l+r+1)/2; 
        auto mid = node; 
        for(int i=l; i<m && mid != nullptr; i++){
            mid = mid->next;
        }
        auto left = helper(node, l, m-1);
        auto right = helper(mid, m+1, r);

        return new TreeNode(mid->val, left, right);

    }
    TreeNode* sortedListToBST(ListNode* head) {
        auto n = getLLSize(head);
        return helper(head, 0, n-1);
    }
};