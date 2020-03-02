/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int,int> frq;
    int top;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        frq.clear();
        top = INT_MIN;
        helper(root);
        vector<int> res;
        for(auto p : frq)
            if(p.second == top) // top is highest frequency
                res.push_back(p.first);
        
        return res;
    }
    
    int helper(TreeNode* curr){
        if(curr == nullptr) return 0;
        int lt = helper(curr->left), rt = helper(curr->right);
        int sum = lt + rt + curr->val;
        frq[sum]++;
        top = max(top, frq[sum]);
        return sum;
    }
};
