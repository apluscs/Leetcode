class Solution {
public:
    struct compar{
        bool operator () (const vector<int>& a, const vector<int>& b) const{
            return a[1]<b[1];
        }
    };
    struct compar2{
        bool operator () (int a, const vector<int>& b) const{ // returns true if a(startTime) is earlier than b's end time
            // cout<<b[1]<<" vs. "<<a<<endl;  // true implies that job with startTime a comes before job with endtime b[1]
            return b[1]>a;
        }
    };

    int jobScheduling(vector<int>& starts, vector<int>& ends, vector<int>& profit) {
        int n=ends.size();
        vector<vector<int>> nums(n,vector<int>(3));
        for(int i=0;i!=n;++i){
            nums[i]={starts[i],ends[i],profit[i]};
        }
        sort(nums.begin(),nums.end(),compar()); // sort by end time
        vector<int> dp(1+n);
        for(int i=0;i!=n;++i){    // now find job out of all that came before i-1 whose end <= nums[i][0]
            // cout<<i<<", ";
            auto it=upper_bound(nums.begin(),nums.begin()+i,nums[i][0],compar2());
            // cout<<i<<", ";
            int j=it-nums.begin();
            // cout<<(*it)[2]<<" ";
            dp[i+1]=max(dp[i],nums[i][2]+dp[j]);
            
            // cout<<dp[i+1]<<" \n";
        }
        return dp[n];
    }
};
