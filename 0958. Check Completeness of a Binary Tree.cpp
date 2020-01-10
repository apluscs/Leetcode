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
    bool isCompleteTree(TreeNode * root) {
      queue < TreeNode * > que;
      que.push(root);
      int found = 0;
      while (!que.empty()) {
        TreeNode * curr = que.front();
        que.pop();
        if (curr == nullptr) {
          if (found == 2) return false; // found another gap... GASP
          found = 1;
          continue; // first gap found
        }
        if (found == 1) found = 2; // found nodes after the initial gap
        que.push(curr - > left);
        que.push(curr - > right);
      }
      return true;
    }
};
