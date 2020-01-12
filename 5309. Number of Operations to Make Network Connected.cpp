class Solution {
  public:
    int makeConnected(int N, vector < vector < int >> & edges) {
      if (edges.size() < N - 1) return -1; // need a cycle = N-1 edges or more
      vector < vector < int >> adj(N);
      for (auto edge: edges) { // adj[i] are all neighbors of i
        int i = edge[0], j = edge[1];
        adj[i].push_back(j);
        adj[j].push_back(i);
      }
      vector < bool > vis(N);
      int res = 0; // count # islands
      for (int i = 0; i != N; i++) {
        if (vis[i]) continue;
        res++; // new island found
        dfs(i, vis, adj);
      }
      return res - 1; // just #islands-1 edges to connect these groups of nodes
    }

  void dfs(int curr, vector < bool > & vis, vector < vector < int >> & adj) {
    if (vis[curr]) return;
    vis[curr] = true; // mark all cells in this island as vis
    for (int nei: adj[curr])
      dfs(nei, vis, adj);
  }
};
