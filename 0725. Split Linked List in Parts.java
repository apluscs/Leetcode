/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode[] splitListToParts(ListNode root, int k) {
        ListNode[] res = new ListNode[k];
        ListNode curr = root;
        int N = 0, ind = 0;
        while (curr != null) { //count how many
            N++;
            curr = curr.next;
        }
        curr = root;
        for (int i = 0; i != N % k; i++) { //slightly longer ones
            res[ind] = new ListNode(-1);
            ListNode temp = res[ind];
            for (int j = 0; j <= N / k; j++) {
                temp = temp.next = new ListNode(curr.val); //create next and make its value at the same time
                curr = curr.next;
            }
            res[ind] = res[ind++].next;
        }
        for (int i = 0; i != k - N % k; i++) {  //all leftovers 
            res[ind] = new ListNode(-1);
            ListNode temp = res[ind];
            for (int j = 0; j != N / k; j++) {
                temp = temp.next = new ListNode(curr.val);
                curr = curr.next;
            }
            res[ind] = res[ind++].next;
        }
        return res;
    }
}
