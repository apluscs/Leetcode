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

    static bool compar(const tuple < int, int, int > & a,
      const tuple < int, int, int > & b) {
      return get < 0 > (a) != get < 0 > (b) ? get < 0 > (a) < get < 0 > (b) : get < 1 > (a) != get < 1 > (b) ? get < 1 > (a) < get < 1 > (b) : get < 2 > (a) < get < 2 > (b); // inc x, dec y coordinate, inc value
    }

  vector < vector < int >> verticalTraversal(TreeNode * root) {
    vector < tuple < int, int, int >> data;
    helper(root, 0, 0, data);
    sort(data.begin(), data.end(), compar);
    int N = data.size();
    vector < vector < int >> res;
    for (int i = 0; i != N; i++) {
      vector < int > curr;
      for (int j = i; j != N && get < 0 > (data[j]) == get < 0 > (data[i]); j++) { // all in the same x coordinate
        curr.push_back(get < 2 > (data[j]));
        i = j; // @ end, i will be last j value of same coordinate
      }
      res.push_back(curr);
    }

    return res;
  }

  void helper(TreeNode * root, int r, int c, vector < tuple < int, int, int >> & data) {
    if (root == nullptr) return;
    data.push_back(make_tuple(r, c, root - > val));
    helper(root - > left, r - 1, c + 1, data);
    helper(root - > right, r + 1, c + 1, data);
  }

};
