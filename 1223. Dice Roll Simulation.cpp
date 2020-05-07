class Solution {
public:
    int mod=1e9+7;
    int dieSimulator(int n, vector<int>& rollMax) {
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(6,vector<int>(16)));
        vector<vector<long>> total(n+1,vector<long>(6));
        for(int s=0;s!=6;++s){
            dp[1][s][1]=total[1][s]=1;
        }
        for(int i=2;i<=n;++i){
            long all=accumulate(total[i-1].begin(),total[i-1].end(),long(0))%mod;  // sum of everything from previous round
            // cout<<"rolls="<<i<<", all="<<all<<endl;
            for(int s=0;s!=6;++s){
                int k=rollMax[s];
                dp[i][s][1]=total[i][s]=(all-total[i-1][s]+mod)%mod;
                // cout<<"dp[i][s][1]="<<dp[i][s][1]<<endl;
                for(int j=2;j<=k;++j){
                    dp[i][s][j]=dp[i-1][s][j-1];
                    total[i][s]=(dp[i][s][j]+total[i][s])%mod;
                    // cout<<"dp[i][s][j]="<<dp[i][s][j]<<endl;

                }
                // cout<<"total for s="<<s<<" is "<<total[i][s]<<endl;
            }
        }
        return accumulate(total[n].begin(),total[n].end(),long(0))%mod;
    }
};
