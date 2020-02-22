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
  int findTilt(TreeNode * root) {
    res = 0;
    helper(root);
    return res;
  }

  int helper(TreeNode * curr) { // return sum of curr's subtree
    if (curr == nullptr) return 0; // 
    int lt = helper(curr - > left), rt = helper(curr - > right);
    res += abs(lt - rt);
    return curr - > val + lt + rt;
  }
};
