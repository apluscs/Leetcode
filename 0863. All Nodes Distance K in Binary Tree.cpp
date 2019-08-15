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
    vector < TreeNode * > prt; //path from root to target 
    int K;
    TreeNode * root, * target;
    bool found;
    vector < int > distanceK(TreeNode * root, TreeNode * target, int K) {
        if (!K) {
            res.push_back(target - > val);
            return res;
        } //K==0
        res.clear();
        prt.clear();
        this - > K = K;
        this - > root = root;
        this - > target = target;
        found = false;
        findTG(root); //find path to target
        // for(TreeNode* tn:prt)cout<<tn->val<<'\t';
        // cout<<endl;
        int len = prt.size() - 1; //exclude target itself

        dfs(K, target); //all kids K steps down from you
        if (root == target) return res; //no need to climb "up", only down
        // for(int tn:res)cout<<tn<<'\t';
        // cout<<endl;
        for (int st = len - 1; st >= 0; st--) {
            TreeNode * b = prt[st + 1] == prt[st] - > left ? prt[st] - > right : prt[st] - > left; 
            //take whichever path  that's not the one with target
            dfs(K - (len - st) - 1, b); //subtract the dist from target to st, then one more for st to b
        }
        if (len >= K) res.push_back(prt[len - K] - > val);
        return res;
    }

    void dfs(int pos, TreeNode * curr) {
        if (curr == NULL) return;
        // cout<<curr->val<<endl;
        if (pos == 0) {
            res.push_back(curr - > val);
            return;
        }
        dfs(pos - 1, curr - > left);
        dfs(pos - 1, curr - > right);

    }

    void findTG(TreeNode * curr) {
        if (found || curr == NULL) return;
        // cout<<"curr: "<<curr->val<<'\t';
        prt.push_back(curr);
        if (curr == target) {
            found = true;
            return;
        }

        findTG(curr - > left);
        findTG(curr - > right);
        if (found) return; //early exit
        prt.erase(prev(prt.end()));
    }
};
