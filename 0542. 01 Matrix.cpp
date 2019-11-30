class Solution {
    public:
        vector < vector < int >> updateMatrix(vector < vector < int >> & matrix) {
            int N = matrix.size();
            if (!N) return matrix;
            int M = matrix[0].size();
            vector < vector < int >> res(N, vector < int > (M, 1e4 + 2));
            //result[i][j]= min(nearest 0 coming from all 4 directions)

            for (int i = 0; i != N; i++) //check in all 4 directions
                for (int j = 0; j != M; j++) {
                    if (matrix[i][j] == 0) res[i][j] = 0;
                    if (i != 0) res[i][j] = min(res[i][j], res[i - 1][j] + 1); //top to bottom
                    if (j != 0) res[i][j] = min(res[i][j], res[i][j - 1] + 1); //left to right
                }
            for (int i = N - 1; i != -1; i--)
                for (int j = M - 1; j != -1; j--) {
                    if (i != N - 1) res[i][j] = min(res[i][j], res[i + 1][j] + 1); //bottom to top
                    if (j != M - 1) res[i][j] = min(res[i][j], res[i][j + 1] + 1); //right to left
                }
            return res;
        }
};
