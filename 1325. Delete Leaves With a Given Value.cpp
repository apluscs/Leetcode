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
    int tar;
  TreeNode * removeLeafNodes(TreeNode * curr, int target) {
    tar = target;
    TreeNode * res = new TreeNode(-1); // dummy, in case curr gets deleted
    res - > left = curr;
    helper(res, tar);
    return res - > left;
  }

  TreeNode * helper(TreeNode * curr, int tar) {
    if (curr != nullptr) {
      TreeNode * lt = helper(curr - > left, tar); // fully solved LHS
      TreeNode * rt = helper(curr - > right, tar); // fully solved RHS
      curr - > left = lt;
      curr - > right = rt;
      if (curr - > left == nullptr && curr - > right == nullptr && curr - > val == tar)
        return nullptr; // "delete" this node
    }
    return curr; // return final version
  }
};
