class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int N = nums.size();
        vector<int> res(N, -1);
        stack<pair<int,int>> st;
        for(int i = 0; i != N; ++i){
            while(!st.empty() && st.top().first < nums[i]){
                auto p = st.top();  st.pop();
                res[p.second] = nums[i];
            }
            st.push(make_pair(nums[i],i));
        }
        for(int i = 0; i != N; ++i){    // literally just do the same thing again, because now it's "circular"
            while(!st.empty() && st.top().first < nums[i]){
                auto p = st.top();  st.pop();
                res[p.second] = nums[i];
            }
            st.push(make_pair(nums[i],i));
        }
        return res;
    }
};
