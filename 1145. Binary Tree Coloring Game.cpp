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
    TreeNode* p1;
    bool btreeGameWinningMove(TreeNode* root, int N, int x) {
        unordered_map<int,int> sums;    // maps node values to # nodes in their subtree
        helper(root, sums, x);
        int lt = p1->left ? sums[p1->left->val] : 0, rt = p1->right ? sums[p1->right->val] : 0, par = sums[root->val] - sums[p1->val], mid = N >> 1;    
        // 3 options: choose left subtree, right subtree, or parent
        // left/right subtrees = blue gets control over that entire subtree
        // parent = blue gets control of everything but p1's subtree (blocks p1 off)
        return lt > mid || rt > mid || par > mid;   // need more than half
    }
    
    int helper(TreeNode* curr, unordered_map<int,int>& sums, int x){   
        if(curr == nullptr) return 0;
        int lt = helper(curr->left, sums, x), rt = helper(curr->right, sums, x);
        if(x == curr->val) p1 = curr;
        sums[curr->val] = 1 + lt + rt;
        return sums[curr->val];
    }  
};
