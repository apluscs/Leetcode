class Solution {
    public:
        int numDistinct(string s, string t) {
            int N = t.length(), M = s.length();
            vector < vector < long >> dp(N + 1, vector < long > (M + 1));
            for (int i = 0; i <= M; i++) dp[0][i] = 1; //one way to make empty string from any substring of s from 0 to i  
            for (int i = 1; i <= N; i++)
                for (int j = 1; j <= M; j++) {
                    dp[i][j] = dp[i][j - 1]; //you can at least discard this char and get the same #ways with all chars before this one
                    if (t[i - 1] == s[j - 1]) dp[i][j] += dp[i - 1][j - 1]; //if you match, new option arises: + #ways to match without last char
                    // cout<<dp[i][j]<<" ";
                }
            // cout<<endl;
            return (int) dp[N][M];
        }
};
