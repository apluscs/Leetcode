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
        unordered_map < int, int > depths;
    TreeNode * subtreeWithAllDeepest(TreeNode * root) {
        depths.clear();
        dfs(root, 0);
        // for(unordered_map<int,int>::iterator it=depths.begin();it!=depths.end();it++) cout<<it->first<<", "<<it->second<<".\t";
        TreeNode * curr = root;
        while (true) {
            if (curr - > left == NULL && curr - > right == NULL) return curr; //the deepest node
            if (curr - > left == NULL) {
                curr = curr - > right;
                continue;
            }
            if (curr - > right == NULL) {
                curr = curr - > left;
                continue;
            }
            int lf = depths[curr - > left - > val], rt = depths[curr - > right - > val], cr = depths[curr - > val];
            if (lf == cr && rt == cr) return curr; //both kids house a "deepest node", so I am their common ancestor
            curr = lf == cr ? curr - > left : curr - > right; //navigate to next node in path to deepest node
        }
        return root;
    }

    int dfs(TreeNode * curr, int depth) {
        if (curr == NULL) return -1;
        depths[curr - > val] = max(depth, dfs(curr - > left, depth + 1)); //max of deepest node in either of 
        depths[curr - > val] = max(depths[curr - > val], dfs(curr - > right, depth + 1)); //two kids' paths
        return depths[curr - > val];
    }
};
