class Solution {
    public:
        int numIslands(vector < vector < char >> & grid) {
            if (grid.size() == 0) return 0;
            int N = grid.size(), M = grid[0].size(), res = 0;
            for (int i = 0; i != N; i++)
                for (int j = 0; j != M; j++) {
                    if (grid[i][j] != '1') continue;
                    res++;
                    queue < pair < int, int >> que;
                    que.push(make_pair(i, j));
                    while (!que.empty()) { // mark all cells of this island as visited
                        pair < int, int > p = que.front();
                        que.pop();
                        int i = p.first, j = p.second;
                        if (i < 0 || i >= N || j < 0 || j >= M || grid[i][j] != '1') continue;
                        grid[i][j] = -1; // mark as visited
                        que.push(make_pair(i + 1, j));
                        que.push(make_pair(i - 1, j)); // neighbors
                        que.push(make_pair(i, 1 + j));
                        que.push(make_pair(i, j - 1));

                    }
                }
            return res;
        }
};
