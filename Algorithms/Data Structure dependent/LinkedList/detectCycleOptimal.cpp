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
    ListNode *detectCycle(ListNode *head) {
        if(!head || !head->next) return nullptr;
        auto slow = head, fast = head, entry = head;

        while(slow && fast){
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
            /* detected cycle */
            if(slow == fast){
                /** 
                 * Define
                 * 1) L1 is defined as the distance between the head point and entry point
                 * 2) L2 is defined as the distance between the entry point and the meeting point
                 * 3) C is defined as the length of the cycle
                 * 
                 * Notes: 
                 * 1) Distance travelled by slow when they meet: L1+L2 - think about it 
                 * - slow travelled L1 to get to cycle and walked L2 before fast caught up 
                 * 2) Distance travelled by fast when they meet: L1+L2+x+L2,
                 *  where x is the remaining length of the cycle (meeting
                 *  point to start of the cycle). 
                 * - obviously we walked L1 steps to get to list 
                 * - fast is faster - so it has waked L2 atleast 2 
                 * times to catch up e.g. it lapped slow
                 * 
                 * Now the math
                 * 
                 * fastDist = 2*slowDist+1 = L1+L2+x+L2 = L1+2L2+x
                 * slowDist = L1+L2
                 * 
                 * fastDist = 2(L1+L2) + 1 = 2L1 + 2L2 + 1
                 *  =>  2L1 + 2L2 = L1+2L2+x1_1
                 *      2L1 = L1+x+1
                 *       L1-1 = x
                 * 
                 * Therefore, the distance fast has travelled more than slow is equal to the distance from the start 
                 * */

                while(slow != entry){
                    slow = slow->next;
                    entry = entry->next;
                }
                return entry;
            }
            
        }

        return nullptr;
    }
};