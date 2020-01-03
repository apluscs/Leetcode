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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==nullptr) return root;
        int pv=p->val, qv=q->val, rv=root->val;
        if(pv> rv && qv>rv) return lowestCommonAncestor(root->right, p, q); // both are on right side
        if(pv< rv && qv<rv) return lowestCommonAncestor(root-> left, p, q); // both are on left side
        return root;    // root is southernmost node that 'splits' q and p
    }
};
