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
    vector < vector < int >> levelOrder(TreeNode * root) {
      vector < vector < int >> res;
      if (root == nullptr) return res;
      queue < TreeNode * > que;
      que.push(root);

      while (!que.empty()) {
        int size = que.size();
        vector < int > level;
        for (int i = 0; i != size; ++i) {
          TreeNode * curr = que.front();
          que.pop();
          level.push_back(curr - > val);
          if (curr - > left) que.push(curr - > left); // need to check for nullity here
          if (curr - > right) que.push(curr - > right); // instead of at beginning bc that would have a random empty level(s)
        }
        res.push_back(level);
      }
      return res;
    }
};
