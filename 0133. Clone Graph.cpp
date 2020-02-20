/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
  public:
    Node * cloneGraph(Node * first) {
      if (first == nullptr) return first;
      vector < Node * > ptrs(101); // 1-100
      vector < bool > vis(101);
      for (int i = 1; i != 101; ++i)
        ptrs[i] = new Node(i); // new Node with appropriate val

      queue < Node * > que;
      que.push(first);
      while (!que.empty()) {
        Node * curr = que.front();
        que.pop();
        int i = curr - > val;
        if (vis[i]) continue;
        vis[i] = true;
        for (Node * nei: curr - > neighbors) {
          ptrs[i] - > neighbors.push_back(ptrs[nei - > val]); // respective Node in new tree adds all respective neighbors in new tree
          que.push(nei);
        }
      }

      return ptrs[1];
    }
};
