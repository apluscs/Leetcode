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
    int res, k;
  bool found;
  int kthSmallest(TreeNode * root, int k) {
    this - > k = k;
    found = false;
    helper(root);
    return res;
  }

  void helper(TreeNode * curr) {
    if (curr == nullptr || found) return;
    helper(curr - > left); // inorder traversal
    k--; // next smallest elem processed
    if (k == 0) {
      found = true; // so other calls can return faster without unnecessary work
      res = curr - > val;
      return;
    }
    helper(curr - > right);
  }
};
