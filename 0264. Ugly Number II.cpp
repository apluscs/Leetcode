class Solution {
    public:
        int nthUglyNumber(int N) {
            if (N == 0) return 0;
            vector < int > dp(N);
            dp[0] = 1;
            int t2 = 0, t3 = 0, t5 = 0; //tx is index of smallest num, when multiplied by x, is > last computed ugly
            for (int i = 1; i != N; i++) {
                dp[i] = min(dp[t2] * 2, min(dp[t3] * 3, dp[t5] * 5));
                if (dp[i] % 2 == 0) t2++; //dp[t2]*2 is no longer > last computed ugly, advance
                if (dp[i] % 3 == 0) t3++; //not exclusive ifs, ex. if you computed 6
                if (dp[i] % 5 == 0) t5++; // you need to advance t2 and t3
            }
            return dp[N - 1];
        }

};
