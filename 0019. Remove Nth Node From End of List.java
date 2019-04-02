/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode curr = new ListNode(-1); //dummy, in case first node is removed
        curr.next = head;
        ListNode end = head;
        head = curr; //saves memory
        for (int i = 0; i < n; i++) end = end.next; //block that extends, hits null when it's time to remove
        while (end != null) {
            curr = curr.next;
            end = end.next;
        }
        curr.next = curr.next.next;
        return head.next; //head = original dummy 
    }
}
