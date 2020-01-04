/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> postorder(Node* root) {
        vector<int> res;
        if(root==nullptr) return res;
        stack<Node*> st;
        st.push(root);
        while(!st.empty()){
            Node* curr=st.top();  st.pop();
            for(Node* kid: curr->children) st.push(kid);
            res.push_back(curr->val);   // order is root, right, left
        }
        reverse(res.begin(), res.end());    // reverse to get post order
        return res;
    }
};
