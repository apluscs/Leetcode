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
    int res, low;
  int findSecondMinimumValue(TreeNode * root) {
    res = INT_MIN;
    low = root - > val;
    helper(root);
    return res == INT_MIN ? -1 : res; // only way for res to be int_min is if curr->val never == root->val
  }

  void helper(TreeNode * curr) {
    if (curr == nullptr) return;
    if (curr - > val != low) { // curr is a child of a node with value root->val
      res = min(res, curr - > val);
      if (res == INT_MIN) res = curr - > val;
      return;
    }
    helper(curr - > right);
    helper(curr - > left);
  }
};
