class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> dp(4, vector<int>(n));
        vector<int> pre(n);
        pre[k-1]=accumulate(nums.begin(),nums.begin()+k,0);
        for(int i=k;i!=n;++i){
            pre[i]=nums[i]+pre[i-1]-nums[i-k];  // = sum of subarray, length k, ending at i
            // cout<<pre[i]<<" ";
        }
        // cout<<endl;
        vector<vector<int>> temp(n);
        vector<vector<int>> memo(n);
        for(int i=1;i!=4;++i){
            for(int j=k-1;j!=n;++j){
                int curr= (j==k-1?0:dp[i-1][j-k])+pre[j];
                vector<int> curr_m = j==k-1? vector<int>() :temp[j-k];  // j's we took to get here
                curr_m.push_back(j);    // we took collection j-k ago(from temp), now with index j
                int a=j==0?0:dp[i][j-1];
                dp[i][j]=max(a,curr);
                
                if(dp[i][j]==a){
                    memo[j]=memo[j-1];
                }else{
                    memo[j]=curr_m;
                }
                // cout<<dp[i][j]<<" ";
                // for(int t:memo[j]) cout<<t<<" ";
                // cout<<"---";
            }
            // cout<<endl;
            swap(temp,memo);
        }
        for(int i=0;i!=3;++i){
            temp[n-1][i] -= k-1;
        }
        return temp[n-1];
    }
};
