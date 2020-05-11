class Solution {
public:
    vector<vector<int>> adj;
    int n,end;
    unordered_map<int,int> dp;
    int countArrangement(int N) {
        n=N;
        end=((1<<n)-1)<<1;
        adj.resize(n+1);
        // cout<<end<<endl;
        for(int i=1;i!=n+1;++i){
            for(int j=1;j!=n+1;++j){
                if(i%j==0 ||j%i==0)adj[i].push_back(j);
            }
        }
        // for(auto ad:adj){
        //     for(int a:ad)cout<<a<<" ";
        //     cout<<endl;
        // }
        return solve(0,1);
    }
    
    int solve(int used, int i){
        // cout<<bitset<4>(used)<<" "<<i<<endl;
        if(used==end)return 1;
        if(dp.count(used))return dp[used];
        int res=0;
        for(int nei:adj[i]){
            int temp=(1<<nei)|used;
            if(temp==used)continue; // already used nei
            res+=solve(temp,i+1);
        }
        dp[used]=res;
        return res;
    }
};
