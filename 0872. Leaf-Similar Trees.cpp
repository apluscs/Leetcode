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
        bool leafSimilar(TreeNode * root1, TreeNode * root2) {
            vector < int > arr1, arr2;
            dfs(root1, arr1);
            dfs(root2, arr2);
            int N = arr1.size();
            if (arr2.size() != N) return false;
            for (int i = 0; i != N; i++)
                if (arr1[i] != arr2[i]) return false; //make sure all values match exactly
            return true;
        }
    void dfs(TreeNode * curr, vector < int > & arr) { //preorder traversal
        if (curr == NULL) return;
        if (curr - > left == NULL && curr - > right == NULL) arr.push_back(curr - > val); //found a leaf
        dfs(curr - > left, arr);
        dfs(curr - > right, arr);
    }
};
