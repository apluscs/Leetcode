
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
        
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL||k==1) return head;
        int num=0;
        ListNode *preheader = new ListNode(-1); //dummy
        preheader->next = head;
        
        ListNode *cur = preheader, *nex, *tmp, *pre = preheader;
        while(cur = cur->next) 
            num++;  //stores length of list
        while(num>=k) { //pre is last in chunk before
            cur = pre->next;    //original 'start' of the k-group
            nex = cur->next;
            for(int i=1;i<k;i++) {  //each iter moves the next 'right' one
                //(nex) to the front of the k-group
                tmp= nex->next;
                nex->next = pre->next;
                pre->next = nex;
                cur->next = tmp;
                nex = tmp;
            }
            pre = cur;
            num-=k; //count how many nodes you processed
        }
        return preheader->next;
    }

};

/*
 Following solution is untested... error in line 46 for some reason
 */
class Solution {
public:
        
    ListNode* helper(Node* curr, Node* prev, int i, int k){
        if(i==k) return curr;
        ListNode* res =helper(curr->next, curr, i+1, k);
        curr->next=prev;
        return res;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy(-1);    dummy->next=head;
        revGroup(head, 0);
        return dummy->next;
    }
    
    ListNode* revGroup(ListNode* curr, int k){
        pair<Node*, bool> p = longEnuff(curr,k);
        if(!(p.second)) return curr;  //now we know it's long enuff
        revGroup(p.start);  //start of next chain
        ListNode* end=helper(curr->next, curr, 1, k);
        
        curr->next=end; //1 succeeds 6
        return curr;
    }

    
    pair<Node*, bool> longEnuff(ListNode* curr, int k){
        int len=0;
        while(curr){
            len++;  //count curr
            if(len == k) return make_pair(curr->next, true);
            curr=curr->next;
        }
        return make_pair(nullptr, false);
    }
};
