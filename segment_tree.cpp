// SEGMENT TREE

struct Node { // lazy range sum, INCLUSIVE s and e
  int start, mid, end, len, sum = 0, lazy = 0;  // lazy range update pending. INDIVIDUAL element changes pending on my
  Node *left = nullptr, *right = nullptr;
 
  Node(int s, int e) {
    start = s;
    end = e;
    mid = (s + e) >> 1;
    len = e + 1 - s;
  }
 
  int update(int f, int t, int delta) {  // set
    if (f > t)
      return sum + lazy * len;  // don't ruin others
    if (f == start && t == end)
      return sum + (lazy += delta) * len;
 
    _emergency();
    sum = left->update(max(f, start), min(t, mid), delta) + right->update(max(f, mid + 1), min(t, end), delta);
    return sum + lazy * len;
  }
 
  int query(int f, int t) {
    if (f > t)
      return 0;  // don't interfere
 
    if (f == start && t == end)
      return lazy * len + sum;
 
    _emergency();
 
    return left->query(max(f, start), min(t, mid))       // left
           + right->query(max(f, mid + 1), min(t, end))  // right;
           + (t + 1 - f) * lazy;                         // quantity * pending on my level
  }
 
  void _emergency() {       // internal func
    if (left == nullptr) {  // emergency build
      left = new Node(start, mid);
      right = new Node(mid + 1, end);
    }
  }
};
