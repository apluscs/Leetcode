class Solution {
public:
    // redo with Manachers
    int minCut(string s) {
        int N = s.length();
        if(N == 0) return 0;
        vector<vector<bool>> valid(N, vector<bool>(N, true));

        // fills upper right half of valid, goes along diagonals
        for(int gap = 1; gap != N; ++gap){  
            for(int i = 0; i + gap != N; ++i){
                int j = i + gap;
                // ends have to match, and so do interiors
                valid[i][j] = s[i] == s[j] && valid[i+1][j-1];    
            }
        }
        vector<int> dp(N, INT_MAX); // dp[i] = minCuts from start of s, to i, inclusive
        for(int i = 0; i != N; ++i){
            for(int j = i; j >= 0; --j){    
                if(valid[j][i]){    // if range from j to i is palindrome
                    int pre = j == 0 ? 0 : dp[j - 1];   // if j == 0, nothing came before it
                    dp[i] = min(dp[i], pre + 1);    // j through i is a palindrome, how many cuts needed for area before?
                }
            }
        }
        return dp[N-1] - 1; // minus the cut at the "end"
        
    }
};
