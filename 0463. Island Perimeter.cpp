class Solution {
    public:
        int islandPerimeter(vector < vector < int >> & grid) {
            if (grid.size() == 0) return 0;
            int N = grid.size(), M = grid[0].size(), res = 0;
            for (int i = 0; i != N; i++)
                for (int j = 0; j != M; j++) {
                    if (grid[i][j] == 0) continue;
                    int waters = 0;
                    if (i == 0 || grid[i - 1][j] == 0) waters++; // water on top 
                    if (i == N - 1 || grid[i + 1][j] == 0) waters++; // water on bottom
                    if (j == 0 || grid[i][j - 1] == 0) waters++; // on left 
                    if (j == M - 1 || grid[i][j + 1] == 0) waters++; // on right
                    res += waters;
                }
            return res;
        }
};
