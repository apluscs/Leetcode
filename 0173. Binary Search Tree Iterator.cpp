/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 // Idk how this uses O(h) memory when it literally puts the entire tree into a queue 
class BSTIterator {
public:
    stack<TreeNode*> st;
    queue<int> que;
    BSTIterator(TreeNode* curr) {
        while(!st.empty()) st.pop();    // clear the stack
        while(!que.empty()) que.pop();
        if(curr == nullptr) return;
        st.push(curr);
        while(!st.empty()){
            curr = st.top();
            st.pop();
            if(!curr->left && !curr->right){    // children have already been processed, or do not need to be processed (no kids)
                que.push(curr->val);
                continue;
            }
            if(curr->right != nullptr){
                st.push(curr->right);
                curr->right = nullptr;  // means highest will be last popped from queue
            }
            st.push(curr);
            if(curr->left != nullptr){
                st.push(curr->left);    // lowest will be first popped from queue
                curr->left = nullptr;
            }
        }
    }
    
    /** @return the next smallest number */
    int next() {
        int res = que.front();
        que.pop();
        return res;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !que.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
