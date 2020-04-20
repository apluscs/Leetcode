class Solution {
public:
    const int MOD = 1e9 + 7;
    int M;
    vector<vector<vector<int>>> dp;
    int numOfArrays(int n, int m, int k) {
        dp.resize(n + 1, vector<vector<int>>(m + 2, vector<int>(k + 1)));
        M = m;
        return solve(n, 1, k);
    }
    
    int solve(int n, int low, int k){   // low = lowest number higher than anything prior
        int range = M - low + 1;    // range of "suprise numbers"
        if(k > range || k > n || k < 0) return 0;
        if(n == 0) return k == 0;   // 
        if(dp[n][low][k]) return dp[n][low][k];
        
        long res = ((long(low) - 1) * solve(n - 1, low, k)) % MOD;  // # non-surprises * how many ways we can make the rest of the array
        for(int m = low; m <= M; ++m){
            res = (res + solve(n - 1, m + 1, k - 1)) % MOD; // try each "surprise number", low shifts upward each time
        }
        dp[n][low][k] = int(res);
        return dp[n][low][k];
    }
};
