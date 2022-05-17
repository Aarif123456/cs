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
    /* Basic reverse procedure */
    private ListNode reverseList(ListNode head){
        ListNode cur = head;
        ListNode old = null;

        while(cur != null){
            ListNode next = cur.next;
            cur.next = old;
            old = cur;
            cur = next;
        }

        return old;
    }

    /* Temp node goes twice as fast - so middle is left in the middle */
    private ListNode getMiddle(ListNode head){
        ListNode tmp = head, middle = head;
        while(tmp.next != null && tmp.next.next != null){
            tmp = tmp.next.next;
            middle = middle.next;
        }

        return middle;
    }

    private ListNode overlayList(ListNode a, ListNode b){
        ListNode start=a, middle = b;
        while(a != null && b != null){
            ListNode tmpA = a.next, tmpB = b.next;
            a.next = b;
            b.next = tmpA;
            a = tmpA;
            b = tmpB;
        }
        return start;
    }

    public void reorderList(ListNode head) {
        if(head == null || head.next == null) return;
        ListNode middle = getMiddle(head);
        middle = reverseList(middle);
        overlayList(head, middle);
    }
}