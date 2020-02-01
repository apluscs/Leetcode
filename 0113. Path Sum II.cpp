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
    vector < vector < int >> res;
  vector < int > path;
  int target;
  vector < vector < int >> pathSum(TreeNode * root, int targ) {
    res.clear();
    path.clear();
    target = targ;
    helper(root, 0);
    return res;
  }

  void helper(TreeNode * curr, int sum) {
    if (curr == nullptr) return;
    path.push_back(curr - > val);
    sum += curr - > val;
    // cout<<sum<<endl;
    if (!curr - > left && !curr - > right && sum == target) res.push_back(path);
    helper(curr - > left, sum);
    helper(curr - > right, sum);
    path.erase(path.begin() + path.size() - 1);
  }
};
