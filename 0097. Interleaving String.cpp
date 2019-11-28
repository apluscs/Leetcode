class Solution {
    public:
        bool isInterleave(string s1, string s2, string s3) {
            int N = s1.length(), M = s2.length();
            if (N + M != s3.length()) return false;
            vector < vector < bool >> dp(N + 1, vector < bool > (M + 1));
            dp[0][0] = true;
            for (int i = 1; i <= M; i++) {
                dp[0][i] = dp[0][i - 1] && s3[i - 1] == s2[i - 1]; //do first i letters of s2 match first i letters of s3
                // cout<<dp[0][i]<<" ";
            }
            // cout<<endl;
            for (int i = 1; i <= N; i++) {
                dp[i][0] = dp[i - 1][0] && s3[i - 1] == s1[i - 1]; //do first i letters of s1 match first i letters of s3
                // cout<<dp[i][0]<<" "; 
            }
            // cout<<endl;
            for (int i = 1; i <= N; i++) {
                for (int j = 1; j <= M; j++) {
                    bool op1 = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1], //use ith char of s1 as last char and can match everything before?
                        op2 = dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]; //use jth char of s2 "      "
                    dp[i][j] = op1 || op2;
                    // cout<< dp[i][j]<<" ";
                    // cout<<s1[i-1]<<", "<<s2[j-1]<<", "<< s3[i+j-2]<<"\t";
                }
                // cout<<endl;
            }
            return dp[N][M];
        }
};
