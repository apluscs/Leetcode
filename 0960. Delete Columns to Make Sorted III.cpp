class Solution {
    public:
        int minDeletionSize(vector < string > & A) {
            int N = A.size(), M = A[0].size(), res = M;
            vector < int > dp(M, 1);
            for (int j = 1; j < M; j++) { // first layer
                for (int k = 0; k != j; k++) { // all columns left of j
                    int i = 0;
                    for (; i != N; i++) // go down each row in this column
                        if (A[i][k] > A[i][j]) break; // not sorted
                    if (i == N) dp[j] = max(dp[j], dp[k] + 1); // only if this column > column i, then we can use it
                }
                res = min(res, M - dp[j]); // for simplified calculations
            }
            return res;
        }
};
