class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int N=nums.size(), curr=nums[0],res=curr;   //curr = max subarray sum ending at i    
        for(int i=1;i!=N;i++){
            curr=max(0,curr)+nums[i];   //distribute the nums[i] inside the max
            res=max(res,curr);
            // cout<<res<<endl;
        }
        return res;
    }
};
