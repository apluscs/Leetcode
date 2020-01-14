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
  int longestUnivaluePath(TreeNode * root) {
    res = 0;
    if (root != nullptr) helper(root);
    return res;
  }

  int helper(TreeNode * curr) { // length of longest univalue chain starting from
    int lf = curr - > left ? helper(curr - > left) : 0,
      rt = curr - > right ? helper(curr - > right) : 0,
      cnlf = curr - > left && curr - > left - > val == curr - > val ? lf + 1 : 0,
      cnrt = curr - > right && curr - > right - > val == curr - > val ? rt + 1 : 0;
    res = max(res, cnlf + cnrt);
    return max(cnlf, cnrt); // will be 0 if neither kid has your val
  }
};

class SolutionSLOW {
  public:
    int longestUnivaluePath(TreeNode * root) {
      if (root == nullptr) return 0;
      return max(helper(root - > right, root - > val) + helper(root - > left, root - > val), max(longestUnivaluePath(root - > right), 
      longestUnivaluePath(root - > left))); // try starting from all possible nodes
    }

  int helper(TreeNode * curr, int val) { // longest chain starting from curr and progressing downward whose nodes are val
    if (curr == nullptr || curr - > val != val) return 0;
    return 1 + max(helper(curr - > left, val), helper(curr - > right, val)); // count curr
  }
};
