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
    vector < TreeNode * > prt;
    int K;
    TreeNode * root, * target;
    bool found;
    vector < int > distanceK(TreeNode * root, TreeNode * target, int K) {
        res.clear();
        prt.clear();
        this - > K = K;
        this - > root = root;
        this - > target = target;
        found = false;
        findTG(root);
        for (TreeNode * tn: prt) cout << tn - > val << '\t';

        // dfs(K,target);  int len=prt.size();
        // if(len>K){
        //     dfs(K-len,root);
        // }else{
        //     res.push_back(prt[len-K]->val);
        // }
        return res;
    }

    void findTG(TreeNode * curr) {

        if (found || curr == NULL) return;
        cout << "curr: " << curr - > val << '\t';
        if (curr == target) {
            found = true;
        }
        prt.push_back(curr);
        findTG(curr - > left);
        findTG(curr - > right);
        if (found) return;
        prt.erase(prev(prt.end()));
    }
};
