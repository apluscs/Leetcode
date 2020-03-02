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
    int sumEvenGrandparent(TreeNode* root) {
        if(root == nullptr) return 0;
        int res = 0;
        if(root->val % 2 == 0){ // you are an even-valued node
            if(root->left){ // add grandchildren, if there are any
                if(root->left->left) res += root->left->left->val;
                if(root->left->right) res += root->left->right->val;
            }
            if(root->right){
                if(root->right->left) res += root->right->left->val;
                if(root->right->right) res += root->right->right->val;
            }
        }
        res += sumEvenGrandparent(root->left) + sumEvenGrandparent(root->right);
        return res;
    }
};
