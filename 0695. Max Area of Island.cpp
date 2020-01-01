class Solution {
    public:
        int maxAreaOfIsland(vector < vector < int >> & grid) {
            if (grid.size() == 0) return 0;
            int N = grid.size(), M = grid[0].size(), res = 0;
            for (int i = 0; i != N; i++)
                for (int j = 0; j != M; j++) {
                    if (grid[i][j] != 1) continue;
                    queue < pair < int, int >> que;
                    que.push(make_pair(i, j));
                    int sz = 0;
                    while (!que.empty()) {
                        pair < int, int > p = que.front();
                        que.pop();
                        int i = p.first, j = p.second;
                        if (i < 0 || i >= N || j < 0 || j >= M || grid[i][j] != 1) continue;
                        sz++;
                        grid[i][j] = -1; // mark as visited
                        que.push(make_pair(i + 1, j));
                        que.push(make_pair(i - 1, j));
                        que.push(make_pair(i, 1 + j));
                        que.push(make_pair(i, j - 1));

                    }
                    res = max(res, sz);
                }
            return res;
        }
};
