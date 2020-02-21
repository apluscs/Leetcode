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
    long total, res;
    const int MOD = 1e9 + 7;
    int maxProduct(TreeNode* root) {
        res = 0; total = 0;
        sum_up(root);
        helper(root);
        return (int)(res % MOD);    // only MOD at the end
    }
    
    void sum_up(TreeNode* curr){
        if(curr == nullptr) return;
        total += curr -> val;   // just get the total sum of all nodes
        sum_up(curr->left);
        sum_up(curr->right);
    }
    
    int helper(TreeNode* curr){
        if(curr == nullptr) return 0;
        int lt = helper(curr->left), rt = helper(curr->right);
        long a = ((total - rt) * rt), b = ((total - lt) * lt);
        res = max(a, max(b, res) ); // try removing edge to left, edge to right
        return curr->val + lt + rt;
    }
};