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
    vector < int > preorder(Node * root) {
      vector < int > res;
      if (root == NULL) return res;
      stack < Node * > st;
      st.push(root);
      while (!st.empty()) {
        Node * curr = st.top();
        st.pop(); // backward so we vist last pushed (first of children ) first
        for (int i = curr - > children.size() - 1; i != -1; i--) st.push(curr - > children[i]); 
        res.push_back(curr - > val); // root, 
      }
      return res;
    }
};
