/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        help(root);
    }
    
    TreeNode* help(TreeNode* root){
        if(!root)return nullptr;
        if(!root->left&&!root->right)return root;
        auto pre=help(root->left);  // last one in left chain
        auto res =help(root->right);    // last one in right chain
        if(!root->right){
            root->right=root->left;
            root->left=nullptr;
            return pre;
        }
        if(!root->left)return res;
        pre->right=root->right;
        root->right=root->left;
        root->left=nullptr;
        return res;
    }
};
