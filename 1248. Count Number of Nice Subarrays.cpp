class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> pre(n+1); 
        for(int i=1;i<=n;++i){
            pre[i]=pre[i-1]+(nums[i-1]%2);
        }
        int i=0,j=0,res=0;
        while(j<=n&&pre[j]!=k)j++;
        while(j<=n){
            int a=1,b=1;    // the original i,j
            j++;    i++;
            while(pre[i]==pre[i-1]){
                i++;
                a++;    // #slots with val=original pre[i]
            }
            while(j<=n&&pre[j]==pre[j-1]){
                j++;
                b++;
            }
            res+=a*b;
        }
        return res;
    }
};
