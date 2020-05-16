/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int res=INT_MIN;
    int maxPathSum(TreeNode* root) {
        solve(root);
        return res;
    }
    int solve(TreeNode*root){
        if(!root)return 0;
        int a=solve(root->left),b=solve(root->right),x=a+b+root->val;
        res=max(res,x);
        return max(max(a,b)+root->val,0);
    }
};
