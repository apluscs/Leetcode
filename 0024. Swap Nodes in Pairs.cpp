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
        ListNode * swapPairs(ListNode * head) {
            ListNode ** pp = & head, * a, * b; //a is curr, b= curr->next
            while ((a = * pp) && (b = a - > next)) { //we have a pair
                a - > next = b - > next; //adjust a's arrow
                b - > next = a; //adjust b's arrow
                * pp = b; //moves second before first
                pp = & (a - > next); //move to the third one
            }
            return head;
        }

};
