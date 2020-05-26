class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        int res=maxSubarray(arr);
        if(k==1)return res;
        int mod=1e9+7,n=arr.size();
        long sum=accumulate(arr.begin(),arr.end(),long(0)), best_end=0,best_start=sum,curr=0;   //best_start starts as sum-empty array
        for(int i=n-1;i!=-1;--i){
            curr+=arr[i];
            best_end=max(best_end,curr);
            best_start=max(best_start,sum-curr);
        }
        if(sum<0)return max(res, int((best_end+best_start)%mod));
        return (sum*(k-2)+best_end+best_start)%mod;
    }
    int maxSubarray(vector<int>& arr){
        int mod=1e9+7;
        long curr=0,res=0;
        for(int a:arr){
            curr=max(curr+a,long(0));
            res=max(res,curr);
        }
        return res%mod;
    }
};
