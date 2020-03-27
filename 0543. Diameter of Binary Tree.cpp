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
    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root, 0).second;   
    }
    
    pair<int,int> helper(TreeNode* curr, int depth){    // max depth of you, max diamter across you
        if(curr == nullptr)
            return make_pair(depth - 1, 0); // so your depth matches your parent
        auto left = helper(curr->left, depth + 1), right = helper(curr->right, depth + 1);
        int res = left.first - depth + right.first - depth; 
        // distance from lowest on your left to you + distance from lowest on your right to you
        return make_pair(max(left.first, right.first), max(max(left.second, right.second), res));  
        // max depths of children, max(diameter going through either child or their subtrees, diameter going through you)
    }
};
