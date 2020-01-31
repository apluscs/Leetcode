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
    vector < string > res;
  vector < string > binaryTreePaths(TreeNode * root) {
    res.clear();
    helper(root, "");
    return res;
  }

  void helper(TreeNode * curr, string s) {
    if (curr == nullptr) return;
    s += to_string(curr - > val);
    if (curr - > left == nullptr && curr - > right == nullptr) { // leaf
      res.push_back(s); // don't append the "->" after the number
      return;
    }
    s += "->";
    helper(curr - > left, s);
    helper(curr - > right, s);
  }
};
