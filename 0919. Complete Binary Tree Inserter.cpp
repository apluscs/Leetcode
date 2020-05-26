/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class CBTInserter {
  public:
    vector < TreeNode * > nodes;

  CBTInserter(TreeNode * root) {
    nodes.resize(1); // first one is dummy
    queue < TreeNode * > que;
    que.push(root);
    while (!que.empty()) {
      TreeNode * curr = que.front();
      que.pop();
      if (curr == nullptr) continue;
      nodes.push_back(curr); // this will go in order of a complete binary tree
      que.push(curr - > left);
      que.push(curr - > right);
    }
  }

  int insert(int v) {
    nodes.push_back(new TreeNode(v));
    int pos = nodes.size() - 1;
    if (pos % 2 == 0) // even = you are left child of someone
      nodes[pos / 2] - > left = nodes[pos];
    else nodes[pos / 2] - > right = nodes[pos]; // odd index
    return nodes[pos / 2] - > val; // parent is index/2
  }

  TreeNode * get_root() {
    return nodes[1];
  }
};

/**
 * Your CBTInserter object will be instantiated and called as such:
 * CBTInserter* obj = new CBTInserter(root);
 * int param_1 = obj->insert(v);
 * TreeNode* param_2 = obj->get_root();
 */
