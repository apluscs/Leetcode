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
    bool isBalanced(TreeNode * root) {
      if (root == nullptr) return true;
      int left = maxDepth(root - > left), right = maxDepth(root - > right);
      return abs(left - right) < 2 && isBalanced(root - > left) && isBalanced(root - > right);
    }

  int maxDepth(TreeNode * root) {
    if (root == nullptr) return 0;
    return max(maxDepth(root - > left), maxDepth(root - > right)) + 1;
  }
};
