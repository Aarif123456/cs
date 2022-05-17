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
    public ListNode reverseList(ListNode head) {
        ListNode cur = head;
        ListNode old = null;

        while(cur != null){
            ListNode nextNode = cur.next;
            cur.next = old;
            old = cur;
            cur = nextNode;
        }

        return old;
    }
}