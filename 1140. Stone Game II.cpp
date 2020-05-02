class Solution {
public:
    vector<int> nums,prefix;
    vector<vector<int>> dp;
    int n;
    int stoneGameII(vector<int>& piles) {
        nums=piles;  
        n=piles.size();
        if(n<3) return accumulate(piles.begin(),piles.end(),0);
        dp.resize(n,vector<int>(n));    // dp[i][j]= max profit if you were Alex, starting at pos i, with M =j
        prefix.resize(n+1);
        for(int i = 1; i != n+1; ++i){
            prefix[i] = piles[i - 1] + prefix[i - 1];
        }
        return solve(0,1);
        
    }
    
    int solve(int start, int m){
        if(start>=n) return 0;
        if(dp[start][m]!=0) return dp[start][m];
        int res=0;
        // cout<<"start="<<start<<", m="<<m<<", res="<<res<<endl;
        for(int i=start;i!=start+2*m&&i!=n;++i){    // take from [start,i]
            int x=i-start+1;    // how many you took
            int curr=prefix[i+1]-prefix[start]-solve(i+1,max(m,x)) +prefix[n]-prefix[i+1];
            res=max(res,curr);
        }
        dp[start][m]=res;
        
        return res;
    }
};
