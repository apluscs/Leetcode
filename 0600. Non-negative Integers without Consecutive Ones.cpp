class Solution {
public:
    int findIntegers(int num) {
        if(num==1)return 2;
        bitset<32> b(num);
        // cout<<b.to_string()<<endl;
        vector<vector<int>> dp(32,vector<int>(2));  // dp[i][j]= #numbers who has i digits, last one=j
        dp[0][0]=1; // exactly one valid number less than 1, that is, 0
        for(int i=1;i!=32;++i){
            dp[i][0]=dp[i-1][1]+dp[i-1][0]; // adding a zero to the end
            dp[i][1]=dp[i-1][0];    // must be a 0 coming before this if last one is a 1
        }
        for(int i=31;i!=0;--i){ // find the largest valid <= num
            if(b[i]&&b[i-1]){ // two 1's in a row
                b[i-1]=0;
                // cout<<i<<endl;
                for(int j=i-2;j>-1;--j){  // alternate 101010 until the end
                    b[j]= ~b[j+1];
                }
                break;
            }
        }
        // cout<<b.to_string();
        int res=0;
        for(int i=31;i!=-1;--i){  // for each one (could be set),
            if(b[i])res+=count(i,dp);  if it were not set and given the prefix from the LHS of the bit representation of the number, the all bits to the right of bit i could be anything, so we just need to look at dp[len-1]
        } // if it were set, we pass this prefix on to the RHS of this bit, ask for how many valid <= RHS are there? 
        return res+1;
    }
    int count(int i,vector<vector<int>>& dp){ // basically #valid with length = i
        // cout<<"i="<<i<<", "<<dp[i][0]+dp[i][1]+1<<endl;
        return dp[i][0]+dp[i][1];
    }
};
