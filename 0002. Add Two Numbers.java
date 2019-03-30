/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
 class Solution {
    public ListNode addTwoNumbers(ListNode a, ListNode b) {
        ListNode res =new ListNode(-1);
        ListNode curr=res;
        int carry=0;    //what excess to carry to next place value
        while(a!=null&&b!=null){
            int sum=a.val+b.val+carry;
            curr.next=new ListNode(sum%10);
            curr=curr.next;
            carry=sum/10;
            a=a.next;
            b=b.next;
        }
        while(a!=null){ //in case one is longer than the other
            int sum=a.val+carry;
            curr.next=new ListNode(sum%10);
            curr=curr.next;
            carry=sum/10;
            a=a.next;
        }
        while(b!=null){
            int sum=b.val+carry;
            curr.next=new ListNode(sum%10);
            curr=curr.next;
            carry=sum/10;
            b=b.next;
        }
        if(carry==1) curr.next=new ListNode(1); //ex. 99+99901
        return res.next;
    }
}
