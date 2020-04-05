class Solution {
public:
    vector<vector<bool>> valid;
    vector<vector<int>> dp;
    int res;
    int minCut(string s) {
        valid.clear();
        dp.clear();
        res = INT_MAX;
        int N = s.length();
        if(N == 0) return 0;
        valid.resize(N, vector<bool>(N, true));
        dp.resize(N, vector<int>(N, -1));
        for(int gap = 1; gap != N; ++gap){
            for(int i = 0; i + gap != N; ++i){
                int j = i + gap;
                valid[i][j] = s[i] == s[j] && valid[i+1][j-1];    // ends have to match, and so do interiors
            }
        }
        return helper(0, N - 1) - 1;    // minus the last cut
    }
    
    int helper(int start, int end){ // returns min #cuts needed for this inclusive range (including the one at the very end)
        if(start > end) return 0;
        if(dp[start][end] != -1) return dp[start][end];
        int res= INT_MAX;
        for(int i = start; i <= end; ++i){
            if(valid[start][i])
                res = min(res, 1 + helper(i+1, end));
        }
        dp[start][end] = res;
        return res;
    }
};
