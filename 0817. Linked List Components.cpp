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
        int numComponents(ListNode * curr, vector < int > & G) {
            int res = 0;
            set < int > nums;
            for (int num: G) nums.insert(num);
            while (curr != NULL) {
                if (nums.find(( * curr).val) != nums.end()) res++; //found a chain of connected components
                while (curr != NULL && nums.find(( * curr).val) != nums.end()) curr = ( * curr).next; 
                //iterate through the chain (may skip this part if first part of linked list is not in set)
                while (curr != NULL && nums.find(( * curr).val) == nums.end()) curr = ( * curr).next; 
                //iterate through this component not in set to prepare for the next one
            }
            return res;
        }
    
        int numComponentsFaster(ListNode * curr, vector < int > & G) {    
            int res = 0;
            unordered_set < int > nums; //faster lookup
            for (int num: G) nums.insert(num);
            while (curr != NULL) { //curr is a pointer = int = can compare with NULL (also int)
                if (nums.count(curr - > val)) res++; //count returns 0 if not there
                while (curr != NULL && nums.count(curr - > val)) curr = curr - > next; //-> dereferences and points
                while (curr != NULL && !nums.count(curr - > val)) curr = curr - > next;
            }
            return res;
        }
};
