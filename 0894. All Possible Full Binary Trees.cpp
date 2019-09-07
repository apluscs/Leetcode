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
        unordered_map < int, vector < TreeNode * >> memo; //tracks all possible subtrees with int nodes
        vector < TreeNode * > allPossibleFBT(int N) {
            if (memo[N].size() != 0) return memo[N]; //already figured out this int
            vector < TreeNode * > res;
            if (N == 1) res.push_back(new TreeNode(0)); //only one node needed
            else { //if(N%2==1)
                for (int lf = 1; lf < N; lf += 2) { //how many nodes are on the left subtree, must be odd
                    int rt = N - 1 - lf; //minus yourself
                    for (TreeNode * left: allPossibleFBT(lf))
                        for (TreeNode * right: allPossibleFBT(rt)) {
                            TreeNode * root = new TreeNode(0); //create a new TreeNode
                            root - > left = left;
                            root - > right = right;
                            res.push_back(root); //one possible subtree formed
                        }
                }
            }
            memo[N] = res;
            return memo[N];
        }
};
