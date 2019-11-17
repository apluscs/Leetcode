class Solution {
    public:
        int minFallingPathSum(vector < vector < int >> & A) {
            int N = A.size(), res = INT_MAX;
            for (int i = 1; i != N; i++) {
                for (int j = 0; j != N; j++) {
                    int left = A[i - 1][max(0, j - 1)], right = A[i - 1][min(N - 1, j + 1)];
                    A[i][j] += min(A[i - 1][j], min(left, right));
                    // cout<<A[i][j]<<" ";
                }
                // cout<<endl;
            }
            for (int j = 0; j != N; j++) {
                res = min(res, A[N - 1][j]);
            }
            return res;
        }
};
