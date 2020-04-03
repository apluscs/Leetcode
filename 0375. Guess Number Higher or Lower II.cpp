class Solution {
public:
    // don't think I could come up with this myself
    // should redo
    int getMoneyAmount(int N) {
        vector<vector<int>> dp(N + 1, vector<int>(N + 1));
        for(int b = 2; b <= N; ++b){
            int k0 = b - 1;
            deque<vector<int>> deq;
            
            for(int a = b - 1; a > 0; --a){
                while(dp[a][k0 - 1] > dp[k0 + 1][b]){
                    k0--;   // k0 is first such that cost(first half) < cost(second half)
                    // and k0 + 1 is last such that cost(first half) > cost(second half)
                }   // run thru this with a = 1, b = 8
                while(!deq.empty() && deq.front()[0] > k0)    // want starting position to include k0 (if starting pos > k0, we would miss the cost of those elems between k0 and this larger num)
                    deq.pop_front();
                
                int v = dp[a + 1][b] + a;   // cost of guessing a + second half
                while(!deq.empty() && deq.back()[1] > v){   // if for some reason cost(v,b) is less than cost (something > v, b), we want the smaller cost
                    deq.pop_back();  
                }
                deq.push_back({a, v});
                
                int f1 = deq.front()[1], f2 = dp[a][k0] + k0 + 1;   
                // f2 = guessing k0 + 1, then first half (guaranteed to be > cost of second half)
                // f1 = guessing k0, then second half (guranteed to be > cost of first half)
                dp[a][b] = min(f1, f2);
            }
        }
        return dp[1][N];
        
    }
};

class Solution {  // simpler, just DFS + memo
public:
    vector<vector<int>> memo;
    int getMoneyAmount(int N) {
        memo.clear();
        memo.resize(N + 1, vector<int>(N + 1, -1));
        return cost(1, N);
    }
    
    int cost(int start, int end){
        if(end <= start) return 0;
        if(memo[start][end] != -1) 
            return memo[start][end];
        int res = INT_MAX;
        for(int i = start; i <= end; ++i){
            int curr = i + max(cost(i + 1, end), cost(start, i - 1));
            res = min(res, curr);
        }
        memo[start][end] = res;
        return res;
    }
};
