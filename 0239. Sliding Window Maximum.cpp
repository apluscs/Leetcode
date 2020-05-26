class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> deq;
        vector<int> res(n-k+1);
        for(int i=0;i!=k;++i){
            while(!deq.empty()&&nums[deq.back()]<nums[i]){  // track indices instead of values
                deq.pop_back();
            }
            deq.push_back(i);
        }
        res[0]=nums[deq.front()];
        for(int i=k;i!=n;++i){
            while(!deq.empty()&&nums[deq.back()]<nums[i]){
                deq.pop_back();
            }
            deq.push_back(i);
            while(!deq.empty()&& deq.front()<=i-k){
                deq.pop_front();    // so you know how much of the front to kick out
            }
            res[i-k+1]=nums[deq.front()];
        }
        return res;
    }
};
