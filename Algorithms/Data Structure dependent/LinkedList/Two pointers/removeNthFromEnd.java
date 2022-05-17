/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode dummy = new ListNode(-1, head);
        ListNode slow = dummy;
        ListNode fast = dummy;
        for(int i=0; i<n; i++){
            if(fast.next != null) fast = fast.next;
            else return head; /* We went past the ending which means nothing gets deleted */
        }

        while(fast.next != null){
            slow = slow.next;
            fast = fast.next;
        }
        if(slow.next != null) slow.next = slow.next.next;
        return dummy.next;
    }
}