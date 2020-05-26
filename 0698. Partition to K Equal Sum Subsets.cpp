class Solution {
public:
    bool res;
    int n,k,target;
    vector<int>nums,buckets,vis;
    bool canPartitionKSubsets(vector<int>& fnums, int k) {
        res=false;
        nums=fnums;
        n=nums.size();
        vis.resize(n);
        target=accumulate(nums.begin(),nums.end(),0);
        if(target%k!=0)return false;
        target/=k;
        buckets.resize(k);
        this->k=k;
        solve(0,0,0);
        return res;
    }
    
    void solve(int b,int curr_sum,int start_index){ // b=which bucket you're on
        if(b==k-1){
            res=true;
        }
        if(res)return;
        if(curr_sum==target){
            solve(b+1,0,0);
            return;
        }
        for(int i=start_index;i!=n;++i){
            if(curr_sum+nums[i]>target || vis[i]) continue;
            vis[i]=true;
            curr_sum+=nums[i];
            solve(b,curr_sum,i+1);
            vis[i]=false;
            curr_sum-=nums[i];
        }
    }
};

class SolutionTLE { // slower because we must wait until the very end to see if the buckets check out
public: // better solution is to fill one bucket at a time, so that we can cut out early if one bucket cannot be filled
    bool res;
    int n,k,target;
    vector<int>nums,buckets;
    bool canPartitionKSubsets(vector<int>& fnums, int k) {
        res=false;
        nums=fnums;
        n=nums.size();
        target=accumulate(nums.begin(),nums.end(),0);
        if(target%k!=0)return false;
        target/=k;
        buckets.resize(k);
        this->k=k;
        solve(0);
        return res;
    }
    
    void solve(int i){
        if(i==n){
            for(int b:buckets)if(b!=target)return;
            res=true;
        }
        if(res)return;
        for(int j=0;j!=k;++j){
            if(buckets[j]+nums[i]>target)continue;
            buckets[j]+=nums[i];
            solve(i+1);
            if(res)return;
            buckets[j]-=nums[i];
        }
    }
};
