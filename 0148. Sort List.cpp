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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;   // 0 or 1 element
        ListNode* a = head, *b = head->next;
        while(b != nullptr && b->next != nullptr){
            a = a->next;
            b = b->next->next;  // b is twice as fast as a
        }
        b = a->next;    // remainder of list after a
        a->next = nullptr;  // end this chunk
        return merge(sortList(head), sortList(b));  // sort the two chunks and then merge
    }
    
    ListNode* merge(ListNode* a, ListNode* b) { // from MergeTwoIntervals
        ListNode res(-1);   ListNode* curr=&res;
        while(a && b)
            if(a->val < b->val){
                curr=curr->next=a;  //tacks on a and advances curr
                a=a->next;  //advance a
            }else{  // if b is less than a
                curr=curr->next=b;
                b=b->next;
            }

        if(a) curr->next=a; //tack on whatever is left, 
        if(b) curr->next=b; //guaranteed to be in the correct order
        return res.next;
    }
};
