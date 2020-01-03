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
        int minDepth(TreeNode * root) {
            if (root == nullptr) return 0;
            int left = minDepth(root - > left), right = minDepth(root - > right);
            return 1 + (left == 0 || right == 0 ? left + right : min(left, right)); 
            // if you lack either a right or left kid, only evaluate the one you do have
        }

};
