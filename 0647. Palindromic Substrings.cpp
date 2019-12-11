class Solution {
    public:
        int countSubstrings(string s) {
            int N = s.length(), res = N; //for single chars
            if (N == 0) return 0; //dp[i][j] = if s.substring(i to j) is a palindrome, main diagonal (single chars) are all true
            vector < vector < bool >> dp(N, vector < bool > (N, true));
            for (int cyc = N - 1; cyc != 0; cyc--) { //diags northeast of main one
                for (int i = 0; i < cyc; i++) {
                    int j = i + N - cyc;
                    dp[i][j] = dp[i + 1][j - 1] && s[j] == s[i]; //everything in the middle must be palindromic && end chars must match
                    if (dp[i][j]) res++;
                }
            }
            return res;
        }
};
