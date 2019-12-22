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
        TreeNode * addOneRow(TreeNode * root, int v, int d) {
            if (root == nullptr) return root;
            if (d == 1) { //special case
                TreeNode * res = new TreeNode(v);
                res - > left = root;
                return res;
            }
            helper(root, v, d - 1);
            return root;
        }

    void helper(TreeNode * curr, int v, int lev) {
        if (curr == nullptr) return;
        if (lev == 1) { //at the d-1 layer
            TreeNode * left = curr - > left; //save curr's left
            TreeNode * right = curr - > right; //and right
            curr - > left = new TreeNode(v);
            curr - > left - > left = left; //reattach as specified
            curr - > right = new TreeNode(v);
            curr - > right - > right = right;
            return;
        }
        helper(curr - > left, v, lev - 1); // lev-- every time
        helper(curr - > right, v, lev - 1);

    }
};
