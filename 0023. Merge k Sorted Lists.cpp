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
        ListNode * mergeKLists(vector < ListNode * > & lists) {
            int jump = 1, N = lists.size();
            if (N == 0) return nullptr;
            while (jump < N) {
                // cout<<jump<<endl;
                for (int i = 0; i + jump < N; i += jump * 2) //jump over the one to merge with to get to the 'first' of the next merge pair
                    lists[i] = merge(lists[i], lists[i + jump]);
                jump *= 2;
            }
            return lists[0]; //all will collpase onto this one
        }

    ListNode * merge(ListNode * a, ListNode * b) { //merges 2 lists into 1
        // cout<<"merging"<<endl;
        ListNode res(-1);
        ListNode * curr = & res;
        while (a && b) {
            // cout<<a->val<<" "<<b->val<<endl;
            if (a - > val < b - > val) {
                curr = curr - > next = a;
                a = a - > next;
            } else {
                curr = curr - > next = b;
                b = b - > next;
            }

        }
        if (a) curr = curr - > next = a;
        if (b) curr = curr - > next = b;
        return res.next;
    }
};

class Solution2 {
    public:
        ListNode * mergeKLists(vector < ListNode * > & lists) {
            ListNode dummy(-1);
            ListNode * curr = & dummy;
            priority_queue < ListNode * , vector < ListNode * > , compar > pq;
            for (ListNode * node: lists)
                if (node) pq.push(node); //load all 'first' nodes
            while (!pq.empty()) {
                ListNode * node = pq.top();
                pq.pop();
                curr = curr - > next = node; //attach node to curr, then move it to this recently attached
                if (node - > next) pq.push(node - > next); //you know that node->next is at least as large as all other nodes in pq currently
            }
            return dummy.next;
        }

    struct compar {
        bool operator()(const ListNode * l,
            const ListNode * r) {
            return l - > val > r - > val;
        }
    };
};
