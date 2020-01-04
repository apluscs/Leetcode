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
    bool isValidBST(TreeNode* root) {
        return helper(root, INT_MIN-1L, INT_MAX+1L);    // negative inf, positive infinite
    }
    
    bool helper(TreeNode* curr, long min, long max){
        if(curr==nullptr) return true;
        if(curr->val <= min || curr->val >= max) return false;
        return helper(curr->right, curr->val, max) && helper(curr->left, min, curr->val);   // rightside must be greater, leftside must be less
    }
};

