/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode fast=head;
        ListNode slow=head;
        while(fast != null && fast.next != null && fast.next.next != null){
            if(fast != null) fast = fast.next.next;
            if(slow != null) slow = slow.next;
            if(fast == slow) return true;
        }

        return false;
    }
}