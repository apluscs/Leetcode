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
    vector<int> postorder, inorder;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this->postorder  = postorder;
        this->inorder   = inorder;
        return helper(0, postorder.size(), 0, inorder.size());
    }
    
     TreeNode* helper(int ps, int pe, int is, int ie){   // bounds for postorder, inorder
        int N = pe - ps;
        if(N == 0) return nullptr;
        TreeNode* curr = new TreeNode(postorder[pe-1]); // known to be root
        for(int i = is; i != ie; ++i)
            if(inorder[i] == curr->val){    // found the root in the inorder
                TreeNode* lt = helper(ps, ps + i - is, is, i), 
                *rt = helper(ps + i - is, pe - 1, i + 1, ie);   // break into regions for left and right children
                curr->left = lt;
                curr->right = rt;
            }
        return curr;
    }
};
