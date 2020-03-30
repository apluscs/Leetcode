class Solution {
public:
    
    struct compar{
        bool operator()(pair<int,int> a, pair<int,int> b){
            return a.first + a.second < b.first + b.second; // greatest at top
        }
    };
    
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k == 0) return {};
        priority_queue<pair<int,int>, vector<pair<int,int>>, compar> pq;
        int N = nums1.size(), M = nums2.size();
        for(int i = 0; i != N; ++i){
            for(int j = 0; j != M; ++j){
                auto curr = make_pair(nums1[i], nums2[j]);
                if(pq.size() == k && curr.first + curr.second >= pq.top().first + pq.top().second)  // we know nums[i] + nums[any later j] has a largest sum than nums[i] + nums[current j], so if pq is already full, we know all those later j's will be popped out --> don't waste time, just cut out
                    break;
                pq.push(curr);
                if(pq.size() > k)
                    pq.pop();   // pop out greatest sum pair
            }
        }
        vector<vector<int>> res;
        while(!pq.empty()){
            auto p = pq.top();
            res.push_back({p.first, p.second});
            pq.pop();
        }
        return res;
    }
};
