class Solution {  // use ascending/descending counts to determine cost in O(1) space next time
public:
    int candy(vector<int>& nums) {
        if(nums.empty())return 0;
        int n=nums.size(),count=1;
        vector<int> A(n,1);
        for(int i=1;i!=n;++i){
            if(nums[i]>nums[i-1]){
                count++;
            }else{
                count=1;
            }
            A[i]=count;
            // cout<<A[i]<<" ";
        }   
        // cout<<endl;
        count=1;
        for(int i=n-2;i!=-1;--i){
            if(nums[i]>nums[i+1]){
                count++;
            }else{
                count=1;
            }
            A[i]=max(count,A[i]);
        }
        return accumulate(A.begin(),A.end(),0);
    }
};
