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
  int sumRootToLeaf(TreeNode * root) {
    res = 0;
    helper(root, 0);
    return res;
  }

  void helper(TreeNode * curr, int num) {
    if (curr == nullptr) return;
    num = (num << 1) + curr - > val; // add on to the number
    if (curr - > left == nullptr && curr - > right == nullptr) { // found a leaf
      res += num;
      return;
    }
    helper(curr - > left, num);
    helper(curr - > right, num);
  }
};
