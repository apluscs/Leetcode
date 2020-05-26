class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size(),res=0,curr=0;
        // cout<<-599%2<<endl;
        unordered_map<int,int> frq;
        frq[0]=1;
        for(int i=0;i!=n;++i){
            curr+=nums[i];
            curr=((curr%k)+k)%k;    // for negative numbers
            res+=frq[curr]; // how many before us have the same sum?
            // cout<<"i="<<i<<", curr="<<curr<<", res="<<res<<endl;
            frq[curr]++;
        }
        return res;
    }
};
