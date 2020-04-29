class Solution {
public:
    const int MOD=1e9+7;
    int sumSubseqWidths(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long base=1,sum=0,res=0;
        for(int i=0,j=n-1;i!=n-1;++i,--j){
            sum=(sum-nums[i]+nums[j])%MOD;
            res=(res+sum*base) %MOD;
            base= (base<<1) %MOD;
        }
        return int(res);
    }
};
