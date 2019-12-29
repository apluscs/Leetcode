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
        vector < int > res;
    vector < int > getAllElements(TreeNode * root1, TreeNode * root2) {
        res.clear();
        helper(root1);
        helper(root2);
        sort(res.begin(), res.end()); // in order traversal helps with the runtime here (I hope)
        return res;
    }

    void helper(TreeNode * curr) {
        if (curr == nullptr) return;
        helper(curr - > left);
        res.push_back(curr - > val); // in order traversal, so these are added in order of least to greatest
        helper(curr - > right);
    }

};
