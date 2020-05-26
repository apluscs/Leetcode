class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n=nums.size(),res=0,i=0;
        Window a,b; // window a to i has k-1 unique, but window a-1 to i has k unique
        // window b to i has k unique, but window b-1 to i has k+1 unique
        for(int i=0;i!=n;++i){
            a.add(nums[i]);
            b.add(nums[i]);
            while(a.j <=i&&a.count>=k){
                a.remove(nums[a.j]);
            }
            while(b.j<=i&&b.count>k){
                b.remove(nums[b.j]);
            }
            res+=a.j-b.j;
            // cout<<a.j<<" "<<b.j<<endl;
        }
        return res;
    }
    
    struct Window{
        int count,j;
        unordered_map<int,int> frq;
        Window():count(0),j(0){}
        void add(int v){
            frq[v]++;
            if(frq[v]==1)count++;
        }
        void remove(int v){
            j++;
            frq[v]--;
            if(frq[v]==0)count--;
        }
    };
};
