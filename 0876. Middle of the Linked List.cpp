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
        ListNode * middleNode(ListNode * head) {
            int N = 0;
            ListNode * curr = head;
            while (curr != NULL) {
                curr = curr - > next; //count how many nodes total in attached to head
                N++;
            }
            // cout<<N;
            curr = head;
            for (int i = 0; i != N / 2; i++) curr = curr - > next; //go exactly halfway
            return curr;
        }
};
