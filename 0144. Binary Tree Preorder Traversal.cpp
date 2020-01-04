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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            TreeNode* curr=st.top();    st.pop();
            if(curr == nullptr)  continue;
            res.push_back(curr->val);
            st.push(curr->right);
            st.push(curr->left);    // so we visit left before right
        }
        return res;
    }
};
