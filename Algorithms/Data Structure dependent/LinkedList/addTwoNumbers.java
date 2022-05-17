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
    private static int getSize(ListNode node){
        int size = 0;
        while(node != null){
            node=node.next;
            size++;
        }

        return size;
    }

    private static ListNode padList(ListNode head, int size){
        ListNode curNode = head;
        for(int i=0; i<size; i++) {
            ListNode pad = new ListNode(0);
            pad.next=curNode;
            curNode = pad;
        }

        return curNode;
    }

    private static ListNode basicSum(ListNode l1, ListNode l2){
        ListNode sum = new ListNode(0);
        ListNode cur = sum;
        while(l1!=null && l2!=null){
            ListNode n = new ListNode(l1.val+l2.val);
            cur.next = n;
            cur = n; 
            l1 = l1.next;
            l2 = l2.next;
        }
        assert(l1 == null && l2 ==null);

        return sum.next;
    }

    private static ListNode fixSum(ListNode head){
        ListNode sum = new ListNode(0);
        sum.next=head;
        recursizeSumFixHelper(sum);

        return sum.val == 0 ? head : sum;
    }

    private static int recursizeSumFixHelper(ListNode node){
        if(node == null) return 0;
        node.val += recursizeSumFixHelper(node.next);
        int carry = node.val/10;
        node.val %= 10;

        return carry;
    }

    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        /* 1. Make list same size */
        int l1Size = getSize(l1);
        int l2Size = getSize(l2);
        if(l1Size<l2Size){
            l1 = padList(l1, l2Size-l1Size);
        }
        else{
            l2 = padList(l2, l1Size-l2Size);
        }

        /* 2. Get sum without worrying about carry */
        ListNode ans = basicSum(l1, l2);

        /* 3. Factor in carry */
        ans = fixSum(ans);

        return ans;
    }
}