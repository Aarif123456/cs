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
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode lessHalf, rightHalf;
        ListNode *curLeft = &lessHalf, *curRight = &rightHalf, *cur=head;
        while(cur != nullptr){
            if(cur->val < x){
                curLeft->next=cur;
                curLeft = cur;
            }
            else{
                curRight->next=cur;
                curRight = cur;
            }
            cur = cur->next;
        }
        /* Left tail points to right half head */
        curLeft->next = rightHalf.next;
        /* Right tail ends the list */
        curRight->next = nullptr; 
        /* Head is usually start of left list unless all value are bigger than partition */
        head = lessHalf.next == nullptr ? head : lessHalf.next;
        
        return head;

    }
};