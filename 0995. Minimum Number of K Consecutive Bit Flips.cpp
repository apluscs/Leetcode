class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n=nums.size(),res=0;
        vector<int> A(n+1);
        int curr=0;
        for(int i=0;i<=n-k;++i){
            curr+=A[i];
            if((curr+nums[i])%2==0){
                res++;
                curr++;
                A[i+k]--;
            }
            // cout<<curr<<" ";
        }
        for(int i=n-k+1;i!=n;++i){
            curr+=A[i];
            if((curr+nums[i])%2==0){
                return -1;
            }
        }
        return res;
    }
};
