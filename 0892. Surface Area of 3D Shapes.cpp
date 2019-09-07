class Solution {
    public:
        int surfaceArea(vector < vector < int >> & grid) {
            int res = 0, N = grid.size();
            int dir[4][2] = { { 0, -1 }, { 0, 1 }, { 1, 0 }, {-1, 0 } };
            for (int i = 0; i != N; i++)
                for (int j = 0; j != N; j++) {
                    // cout<<i<<", "<<j<<endl;
                    if (grid[i][j] == 0) continue;
                    res += 2;
                    for (int k = 0; k != 4; k++) {
                        int ni = i + dir[k][0], nj = j + dir[k][1], nv = 0;
                        if (ni != -1 && ni != N && nj != -1 && nj != N) nv = grid[ni][nj];
                        res += max(0, grid[i][j] - nv);
                    }
                }
            return res;
        }
};
