#define print_arr(arr, _n) \
  {for(int _i =0; _i<_n; ++_i)               \
  cout << arr[_i] << " ";  \
  cout << endl; }
class Solution {
public:
  int total[20001] = {0}, n, tree[100005], m;
  unordered_set<int> adj[20001];
  vector<int> countPairs(int n, vector<vector<int>>& edges, vector<int>& queries) {
    vector<int> res;
    this->n = n, m = edges.size();
    unordered_map<pair<int,int>, int, pair_hash> between;  // between = #edges directly between (u,v)
    for(auto& e : edges){
      if(e[0] > e[1]) swap(e[0], e[1]);
      between[{e[0], e[1]}]++, total[e[0]]++, total[e[1]]++, adj[e[0]].insert(e[1]);
    } 
    // print_arr(total, n+1);
    for(int q : queries) {
      int curr = 0;
      for(auto& p : between) {  // pairs with direct edge in between
        int u = p.first.first, v = p.first.second, b = p.second;
        curr += total[u] + total[v] - b > q;
      }
      // cout << curr << endl;
      res.push_back(curr + solve(q));
    }
    return res;
  }
  int solve(int q) {  // want to know pairs without a direct edge that have total[u] + total[v] > q
    int res = 0;
    memset(tree, 0, (m+5)*4);
    for(int i=1; i<=n; ++i) {
      update(total[i], 1);
    }
    for(int i=1; i<=n; ++i) {
      update(total[i], -1); // things to remove: yourself, all direct-edged neighbors
      for(int j : adj[i]) update(total[j], -1);
      res += n - i - adj[i].size() - query(q - total[i]); // how many are in the tree?
      // res += query(100000) - query(q - total[i]); // how many are in the tree?
      for(int j : adj[i]) update(total[j], 1);
    }
    return res;
  }
  void update(int v, int d) {  // d is the incoming change
    // printf("v=%d, d=%d\n", v,d);
    for (int i = v+1; i <= m+1; i += (i & -i)) tree[i] += d;
  }
  int query(int v) {
    int res = 0;
    for (int i = v+1; i>0; i -= (i & -i)) res += tree[i];
    return res;
  }
  struct pair_hash {
    template <class T1, class T2>
    size_t operator()(pair<T1, T2> const& pair) const {
      size_t h1 = std::hash<T1>()(pair.first);
      size_t h2 = std::hash<T2>()(pair.second);

      return h1 ^ h2;
    }
  };
};
