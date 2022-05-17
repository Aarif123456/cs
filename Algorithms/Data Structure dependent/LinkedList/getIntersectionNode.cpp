/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int getLength(ListNode *cur){
        int size = 0;
        while(cur){
            cur = cur->next;
            size++;
        }
        return size;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int sizeA = getLength(headA), sizeB = getLength(headB);
        return getIntersectionNode(headA, headB, sizeA, sizeB);
    }

private:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB, int sizeA, int sizeB){
        if(sizeA < sizeB) return getIntersectionNode(headB, headA, sizeB, sizeA);
        for(int i = 0; i < sizeA-sizeB; i++){
            headA = headA->next;
        }

        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }


        return headA;
    }
};