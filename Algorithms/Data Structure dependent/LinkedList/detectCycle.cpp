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
        if(!head) return nullptr;
        auto slow = head, fast = head->next;
        while(slow && fast){
            /* found cycle */
            if(slow == fast){
                int cycleLen = 1;
                auto cur = slow->next;
                while(cur != slow){
                    cur = cur->next;
                    cycleLen++;
                }

                fast = head;

                for(int i = 0; i < cycleLen; i++){
                    fast = fast->next;
                }

                auto meeter = head;
                while(meeter != fast){
                    fast = fast->next;
                    meeter = meeter->next;
                }
                return meeter;

            }
            slow = slow->next;
            fast = fast->next;
            if(fast) fast = fast->next;
        }

        return nullptr;
    }
};