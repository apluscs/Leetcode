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
    vector<int> preorder, inorder;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        this->preorder  = preorder;
        this->inorder   = inorder;
        return helper(0, preorder.size(), 0, inorder.size());
    }
    
    TreeNode* helper(int ps, int pe, int is, int ie){   // bounds for preorder, inorder
        int N = pe - ps;
        if(N == 0) return nullptr;
        TreeNode* curr = new TreeNode(preorder[ps]); // known to be root
        for(int i = is; i != ie; ++i)
            if(inorder[i] == curr->val){    // found the root in the inorder
                TreeNode* lt = helper(ps + 1, ps + i - is + 1, is, i), 
                *rt = helper(ps + i - is + 1, pe, i + 1, ie);   // break into regions for left and right children
                curr->left = lt;
                curr->right = rt;
            }
        return curr;
    }
};
