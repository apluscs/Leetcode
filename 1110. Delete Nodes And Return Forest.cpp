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
    unordered_set < int > toDel;
  vector < TreeNode * > res;

  vector < TreeNode * > delNodes(TreeNode * root, vector < int > & to_delete) {
    res.clear();
    toDel.clear();
    for (int num: to_delete) toDel.insert(num);
    helper(root, true);
    return res;
  }

  TreeNode * helper(TreeNode * curr, bool top) {
    if (curr == nullptr) return nullptr;
    bool top2 = toDel.count(curr - > val) != 0; // if curr should be deleted
    toDel.erase(curr - > val);
    TreeNode * right = helper(curr - > right, top2);
    TreeNode * left = helper(curr - > left, top2);
    curr -> right = right;
    curr -> left = left;
    if (top && !top2) res.push_back(curr); // top and not deleted
    return top2 ? nullptr : curr; // if curr was deleted, return nullptr
  }
};
