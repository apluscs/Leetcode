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
    string smallestFromLeaf(TreeNode * root, string s = "") {
      if (root == nullptr) return "|"; // larger than 'z'
      s = (char)(root - > val + 'a') + s; // add self to front of s
      return !root - > left && !root - > right ? s : min(smallestFromLeaf(root - > left, s), smallestFromLeaf(root - > right, s)); 
      // if leaf, return self
    }
};
