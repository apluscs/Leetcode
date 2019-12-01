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
        ListNode * mergeTwoLists(ListNode * a, ListNode * b) {
            ListNode res(-1);
            ListNode * curr = & res;
            while (a && b)
                if (a - > val < b - > val) {
                    curr = curr - > next = a; //tacks on a and advances curr
                    a = a - > next; //advance a
                } else { // if b is less than a
                    curr = curr - > next = b;
                    b = b - > next;
                }

            if (a) curr - > next = a; //tack on whatever is left, 
            if (b) curr - > next = b; //guaranteed to be in the correct order
            return res.next;
        }
};
