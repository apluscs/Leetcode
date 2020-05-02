class Solution {
public:
    int m;
    int findRotateSteps(string ring, string key) {
        unordered_map<char,vector<int>> inds;  
        m=ring.length();
        int n=key.length();
        vector<vector<int>> dp(n,vector<int>(m,INT_MAX));
        for(int i=0;i!=m;++i){
            inds[ring[i]].push_back(i);
            if(ring[i]==key[0])
                dp[0][i]=dist(0,i)+1;   // #moves  
            // cout<<dp[0][i]<<" ";
        }
        // cout<<endl;
        for(int i=1;i!=n;++i){
            for(int j:inds[key[i]]){    // all possible places we could land on
                int best=INT_MAX;
                for(int k:inds[key[i-1]]){  // all possible places we could have came from
                    int curr=dp[i-1][k]+dist(j,k)+1;
                    // cout<<curr<<", "<<j<<", "<<k<<", "<<dist(j,k)<<endl;
                    if(curr<best) best=curr;
                }
                dp[i][j]=best;
                // cout<<best<<" ";
            }
            // cout<<endl;
        }
        int res=INT_MAX;
        for(int j=0;j!=m;++j){
            res=min(res,dp[n-1][j]);
        }
        return res;
        
    }
    int dist(int a, int b){
        return min(abs(a-b),m-abs(a-b));
    }
};
