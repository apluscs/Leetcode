class Solution {  // modeled after #1024
public:
    int minTaps(int n, vector<int>& ranges) {
        int res=1,end=-1,i=0;   //res=1 for initial tap
        vector<int> nums(n+1,-1);
        for(int i=0;i<=n;++i){
            int s=max(0,i-ranges[i]),e=i+ranges[i];
            nums[s]=max(e,nums[s]); // nums[i]=rightmost pos range starting at i covers

        }
        if(nums[0]==-1) return -1;
        end=nums[0];
        i=0;
        while(end<n&&i<=n){
            int best_end=0;
            if(i>end) return -1;    // some interval can't cover
            while(i<=end){
                if(nums[i]>best_end)
                    best_end=nums[i];
                i++;
            }
            end=best_end;
            res++;
        }
        return res;
    }
};
