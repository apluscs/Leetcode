class Solution {
    public:
        int numSquares(int N) {
            if (N <= 0) return 0;
            static vector < int > dp({ 0 });  //values in here remain the same every time, so don't waste time recomputing stuff 
            dp[0] = 0;  
            while (dp.size() <= N) {  //only compute dp at values you don't know the answer to
                int i = dp.size(), res = INT_MAX;
                for (int j = 1; j * j <= i; j++)
                    res = min(res, dp[i - j * j] + 1);
                dp.push_back(res);
            }
            return dp[N];
        }
};

class Solution2 {
    public:
        int numSquares(int N) {
            if (N <= 0) return 0;
            vector < int > dp(N + 1, INT_MAX);
            dp[0] = 0;
            for (int i = 1; i != N + 1; i++)
                for (int j = 1; j * j <= i; j++) //try subtracting all perf squares <= i
                    dp[i] = min(dp[i], dp[i - j * j] + 1); // option: #ways without j*j, then add j*j (+1 square)
            return dp[N];
        }
};
