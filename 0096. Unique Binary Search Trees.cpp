class Solution {
    public:
        int numTrees(int N) {
            vector < int > dp(N + 1);
            dp[0] = dp[1] = 1;
            for (int root = 2; root != N + 1; root++) {
                for (int sp = 1; sp != root + 1; sp++) { //each possible splitting pt
                    dp[root] += dp[sp - 1] * dp[root - sp];
                }
            }
            return dp[N];
        }
};
