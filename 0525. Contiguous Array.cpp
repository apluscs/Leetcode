class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int count =0,res=0,n=nums.size();
        unordered_map<int,int> m;
        m[-1]=-1;
        for(int i=0;i!=n;++i){
            count+=nums[i];
            int x=i-2*count;
            if(m.count(x)){
                res=max(res,i-m[x]);
            } else {
                m[x]=i;
            }
        }
        return res;
    }
};
