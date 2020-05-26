class Solution {    // top down
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


class Solution {    // actually in Java, bottom up
    public int numOfArrays(int N, int M, int K) {
        final long MOD = (long) 1E9+7;
        long[][][] dp = new long[K+1][N+1][M+1];
        dp[0][0][0]=1;  // when it works out perfectly ex. n = 1, m = 1, k = 1, put down 1 in first slot --> 
        
        for(int k = 1; k<=K; k++){
            for(int n = k; n<=N; n++){
                for(int m = 0; m<=M; m++){
                    dp[k][n][m] = (dp[k][n-1][m]*m) % MOD;  // how many ways to build n - 1 elems that don't exceed the maximum m ?
                    for(int i = 0; i<m; i++){   // try putting down value i + 1 in last pos
                        dp[k][n][m] += (dp[k-1][n-1][i]) % MOD; // everything that came before must be <= i + 1 in order for it to be a surprise
                    }
                }
            }
        }
        
        long ans = 0; 
        for(int i = 0; i<=M; i++){
            ans+=dp[K][N][i]%MOD;
        }
        return (int) (ans%MOD); 
    }
}
