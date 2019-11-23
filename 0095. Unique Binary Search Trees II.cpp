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
        vector < TreeNode * > generateTrees(int N) {
            if (!N) return vector < TreeNode * > ();
            return helper(1, N);
        }

    vector < TreeNode * > helper(int start, int end) {
        vector < TreeNode * > res;
        if (start > end) res.push_back(nullptr);
        for (int root = start; root != end + 1; root++) { //each possible root
            vector < TreeNode * > left = helper(start, root - 1), right = helper(root + 1, end);
            for (TreeNode * lt: left) { //iterate over possible left subtrees
                for (TreeNode * rt: right) { //couple with every possible right subtree
                    TreeNode * curr = new TreeNode(root);
                    curr - > left = lt;
                    curr - > right = rt;
                    res.push_back(curr);
                }
            }
        }
        return res;
    }
};
