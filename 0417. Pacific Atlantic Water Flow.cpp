class Solution {
    public:
        vector < vector < int >> pacificAtlantic(vector < vector < int >> & grid) {
            vector < vector < int >> res;
            unordered_set < int > pac, atl;
            if (grid.size() == 0) return res;
            int N = grid.size(), M = grid[0].size();
            const int dir[4][2] = { { 1, 0 }, { 0, -1 }, {-1, 0 }, { 0, 1 } };
            queue < pair < int, int >> que;
            for (int i = 0; i != N; i++) que.push(make_pair(i, 0)); // left side
            for (int j = 0; j != M; j++) que.push(make_pair(0, j)); // top side
            while (!que.empty()) {
                pair p = que.front();
                que.pop();
                int i = p.first, j = p.second;
                if (pac.count(i * M + j)) continue;
                pac.insert(i * M + j); // mark what cells pacific waters can reach
                for (int d = 0; d != 4; d++) { // all 4 neighbors
                    int ni = i + dir[d][0], nj = j + dir[d][1];
                    if (ni < 0 || ni >= N || nj < 0 || nj >= M || pac.count(ni * M + nj) || grid[ni][nj] < grid[i][j])
                continue; // only neighbors greater than you - then water can flow from them to you
                    que.push(make_pair(ni, nj));
                }
            }

            for (int i = 0; i != N; i++) que.push(make_pair(i, M - 1)); // right side
            for (int j = 0; j != M; j++) que.push(make_pair(N - 1, j)); // bottom side
            while (!que.empty()) { // almsot the same exact process as pacific queue
                pair p = que.front();
                que.pop();
                int i = p.first, j = p.second;
                if (atl.count(i * M + j)) continue; // don't process if visited
                if (pac.count(i * M + j)) res.push_back({ i, j }); // if this can reach pacific too
                atl.insert(i * M + j);
                for (int d = 0; d != 4; d++) {
                    int ni = i + dir[d][0], nj = j + dir[d][1];
                    if (ni < 0 || ni >= N || nj < 0 || nj >= M || atl.count(ni * M + nj) || grid[ni][nj] < grid[i][j]) continue;
                    que.push(make_pair(ni, nj));
                }
            }
            return res;

        }
};
