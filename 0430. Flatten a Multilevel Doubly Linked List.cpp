/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(!head)return head;
        help(head);
        return head;
    }
    Node* help(Node* curr){
        while(true){
            if(!curr->child&&!curr->next)return curr;   // reached end of chain
            if(curr->child){
                auto temp=help(curr->child);
                temp->next=curr->next;
                curr->child->prev=curr;
                if(curr->next)curr->next->prev=temp;
                curr->next=curr->child;
                curr->child=nullptr;
            }
            curr=curr->next;
        }
        return nullptr;
    }
};
