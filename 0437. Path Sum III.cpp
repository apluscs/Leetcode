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
    int pathSum(TreeNode * root, int sum) {
      if (root == nullptr) return 0; // second and third parts allow us to start the pre at every possible node
      return helper(root, 0, sum) + pathSum(root - > left, sum) + pathSum(root - > right, sum);
    }

  int helper(TreeNode * root, int pre, int target) {
    if (root == nullptr) return 0;
    int curr = pre + root - > val;
    return helper(root - > left, curr, target) + helper(root - > right, curr, target) + (curr == target ? 1 : 0);
  }
};
