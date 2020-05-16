class Solution {
public:
    int numDecodings(string s) {
        int n=s.length(),prev=1,mod=1e9+7;
        s="  "+s;
        vector<long> dp(n+2); 
        dp[1]=1;
        for(int i=2;i!=n+2;++i){
			// one before this must be '1' or '2'; this is essentialy dp[i-2]*(whether s[i-1] can be '1' + whether s[i-1] can be '2')
            if(s[i]=='0') dp[i]=(s[i-1]=='1'||s[i-1]=='*')*dp[i-2]+(s[i-1]=='2'||s[i-1]=='*')*dp[i-2];  
            
			// this digit can go by itself OR tag along with s[i-1] if it can be '1' OR tag along with s[i-1] if it can be '2' AND s[i] is < '7' (because > 27 is not valid)
            else if(isdigit(s[i])) dp[i]=dp[i-1]+ ((s[i-1]=='1'||s[i-1]=='*')*dp[i-2]) +((s[i-1]=='2'||s[i-1]=='*')&&s[i]<'7')*dp[i-2];  
            
            else
                for(int d=1;d!=10;++d) // try all possible ways the * could go
                    dp[i]+=dp[i-1]+ ((s[i-1]=='1'||s[i-1]=='*')*dp[i-2]) +((s[i-1]=='2'||s[i-1]=='*')&&d<7)*dp[i-2]; // same logic as the else-if
            
			dp[i]%=mod;
        }
        return dp.back();
    }
};
