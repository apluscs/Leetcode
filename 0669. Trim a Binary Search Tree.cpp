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
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        if(root == nullptr) return root;
        if(root->val > R) return trimBST(root->left, L, R); // root is too big, cut it out
        if(root->val < L) return trimBST(root->right, L, R); // root is too small
        root->left = trimBST(root->left, L, R); // all the cutouts will be handled by chilidren's call
        root->right = trimBST(root->right, L, R);
        return root;
    }
};
