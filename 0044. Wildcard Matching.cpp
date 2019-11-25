class Solution {
    public:
        bool isMatch(string tar, string key) {
            int N = key.length(), M = tar.length();
            vector < vector < bool >> dp(N + 1, vector < bool > (M + 1));
            dp[0][0] = true; //empty strings match
            for (int i = 1; i <= N; i++) {
                if (key[i - 1] == '*') dp[i][0] = dp[i - 1][0]; //you can also match the empty string (?)
                bool found = dp[i - 1][0];
                for (int j = 1; j <= M; j++) {
                    char curr = key[i - 1];
                    found |= dp[i - 1][j]; //keep checking for match
                    if (curr >= 'a' && curr <= 'z') { //normal case: you need to match, and everything before i in key needs to match with everything before j in target
                        dp[i][j] = curr == tar[j - 1] && dp[i - 1][j - 1];
                    } else if (curr == '?') { //you can be anything, so only respective prev substrings need to match
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = found; //if there exists a true in row above from j=0 to j=j
                    }
                    // cout<<dp[i][j]<<" ";
                }
                // cout<<endl;
            }
            return dp[N][M];
        }
};
