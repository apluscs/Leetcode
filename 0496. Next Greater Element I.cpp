class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int N = nums1.size(), M = nums2.size();
        vector<int> res(N, -1);
        unordered_map<int,int> map;
        stack<int> st;  // is decreasing
        for(int num : nums2){
            while(!st.empty() && st.top() < num){
                map[st.top()] = num;
                st.pop();
            }   // each "large" number clears out all "smaller" numbers that came before it
            st.push(num);
        }
        for(int i = 0; i != N; ++i){
            if(map.count(nums1[i]) == 0) continue;  // nothing greater than for nums1
            res[i] = map[nums1[i]];
        }
        return res;
    }
};
