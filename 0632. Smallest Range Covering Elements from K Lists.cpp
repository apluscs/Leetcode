class Solution {
public:
    struct Ptr{
        int i,j,v;
        Ptr(int i, int j, int v):i(i),j(j),v(v){}
        bool operator < (const Ptr& b) const{
            return v>b.v;
        }
        
    };
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int n=nums.size(),high=INT_MIN,low=INT_MAX;
        vector<int> res={0,INT_MAX};
        priority_queue<Ptr> pq; // max heap
        for(int i=0;i!=n;++i){
            if(nums[i].empty()) continue;
            pq.push(Ptr(i,0,nums[i][0]));
            high=max(high,nums[i][0]);  // tracks max and min of what's in the pq
        }
        while(true){
            // cout<<high<<endl;
            auto p=pq.top();    pq.pop();
            if(high-p.v<res[1]-res[0]){
                // cout<<p.v<<endl;
                res={p.v,high};
            }
            if(p.j==nums[p.i].size()-1){
                break;
            } 
            pq.push(Ptr(p.i,p.j+1,nums[p.i][p.j+1]));
            high=max(high,nums[p.i][p.j+1]);
        }
        return res;
    }
};
