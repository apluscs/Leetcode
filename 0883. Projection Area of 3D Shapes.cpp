class Solution {
    public:
        int projectionArea(vector < vector < int >> & grid) {
            int N = grid.size();
            int hts[2][N], res = 0; //second row is for columns (parallel to y axis)
            for (int i = 0; i != 2; i++)
                for (int j = 0; j != N; j++)
                    hts[i][j] = 0;
            for (int i = 0; i != N; i++)
                for (int j = 0; j != N; j++) {
                    int h = grid[i][j];
                    if (h == 0) continue;
                    hts[0][i] = max(hts[0][i], h);
                    hts[1][j] = max(hts[1][j], h);
                    res++; //x and y - count every cell != 0
                }
            for (int i = 0; i != 2; i++) //x and z - for each x-row with a height, get max height for that row and add
                for (int j = 0; j != N; j++) {
                    res += hts[i][j]; //y and z - for each y-col with a height, get max height for that col and add
                    // cout<<hts[i][j]<<'\t';
                }

            return res;
        }



};
