class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num+1);
        for(int i=0,j=0;i<=num;++i,j=1-j){
            dp[i]=dp[i>>1]+j;
        }
        return dp;
    }
};
