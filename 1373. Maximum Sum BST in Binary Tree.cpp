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
    int res=0;
    int maxSumBST(TreeNode* root) {
        solve(root);
        return res;
    }
    vector<int> solve(TreeNode*root){   // isbst, subtree sum, max elem, min elem
        if(!root){  
            return {1,0,INT_MIN,INT_MAX};
        }
        auto a=solve(root->left),b=solve(root->right);
        int is_bst=a[0]&&b[0]&&root->val>a[2]&&root->val<b[3],sum=a[1]+b[1]+root->val;
        if(is_bst)res=max(res,sum);
        auto res={is_bst,sum,max(root->val,max(a[2],b[2])),min(root->val,min(a[3],b[3])) };
        // for(int r:res)cout<<r<<" ";cout<<root->val<<endl;
        return res;
    }
};
