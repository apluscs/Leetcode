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
        bool isSymmetric(TreeNode * root) {
            if (!root) return true;
            queue < pair < TreeNode * , TreeNode * >> que;
            que.push(make_pair(root - > left, root - > right));
            while (!que.empty()) {
                pair < TreeNode * , TreeNode * > p = que.front();
                que.pop();
                TreeNode * a = p.first;
                TreeNode * b = p.second;
                if (!a && !b) continue; // same logic as below
                if (!a || !b || a - > val != b - > val) return false;
                que.push(make_pair(a - > left, b - > right)); // inners and outers
                que.push(make_pair(b - > left, a - > right));
            }
            return true;
        }

};

class Solution2 {
    public:
        bool isSymmetric(TreeNode * root) {
            return !root || helper(root - > left, root - > right); // root could be null
        }

    bool helper(TreeNode * a, TreeNode * b) {
        if (!a && !b) return true; // both are null 
        if (!a || !b || a - > val != b - > val) return false; // only one is null, or vals !=
        return helper(a - > right, b - > left) && helper(a - > left, b - > right); // inners need to be mirrors, so do outers
    }
};
