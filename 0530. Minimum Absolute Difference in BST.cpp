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
    int res;
  TreeNode * prev;

  int getMinimumDifference(TreeNode * root) {
    res = INT_MAX;
    prev = nullptr;
    helper(root);
    return res;
  }

  void helper(TreeNode * root) {
    if (root == nullptr) return;
    helper(root - > left); // in order traversal, processes BST in sorted order
    if (prev) res = min(res, abs(prev - > val - root - > val));
    prev = root;
    helper(root - > right);
  }
};
