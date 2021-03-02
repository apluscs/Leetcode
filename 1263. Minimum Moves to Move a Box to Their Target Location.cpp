#define FOR(a, b, c) for (int(a) = (b); (a) < (c); ++(a))
#define REP(i, n) FOR(i, 0, n)
class Solution {
 public:
  struct State {
    int i, j, bi, bj, ps;
    State(int i, int j, int bi, int bj, int ps) : i(i), j(j), bi(bi), bj(bj), ps(ps) {}
  };
  int n, m;
  bool vis[20][20][20][20];
  const int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int minPushBox(vector<vector<char>>& grid) {
    n = grid.size(), m = grid[0].size(), memset(vis, false, sizeof(vis));
    deque<State> que;
    State curr(-1, -1, -1, -1, 0);
    REP(i, n)
    REP(j, m) if (grid[i][j] == 'B') curr.bi = i,
                                     curr.bj = j;
    else if (grid[i][j] == 'S') curr.i = i, curr.j = j;
    que.push_back(curr);
    int res = 0;
    while (!que.empty()) {
      curr = que.front(), que.pop_front();
      int i = curr.i, j = curr.j, bi = curr.bi, bj = curr.bj;
      if (grid[bi][bj] == 'T') return curr.ps;
      for (auto d : dir) {
        int ni = i + d[0], nj = j + d[1];
        if (ni == bi && nj == bj) {  // we can actually push the box
          int nbi = bi + d[0], nbj = bj + d[1];
          if (out(nbi, nbj) || grid[nbi][nbj] == '#' || vis[ni][nj][nbi][nbj]) continue;
          vis[ni][nj][nbi][nbj] = true, que.push_back(State(ni, nj, nbi, nbj, curr.ps + 1));
          continue;
        }
        if (out(ni, nj) || grid[ni][nj] == '#' || vis[ni][nj][bi][bj]) continue;     // out or blocked
        vis[ni][nj][bi][bj] = true, que.push_front(State(ni, nj, bi, bj, curr.ps));  // try simply moving yourself
      }
    }
    return -1;
  }
  bool out(int i, int j) { return i <= -1 || i >= n || j <= -1 || j >= m; }
};
