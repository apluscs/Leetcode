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
    TreeNode * invertTree(TreeNode * curr) {
      if (curr == nullptr) return curr;
      TreeNode * temp = curr - > left;
      curr - > left = curr - > right; // switch left and right
      curr - > right = temp;
      invertTree(curr - > left);
      invertTree(curr - > right);
      return curr;
    }
};
