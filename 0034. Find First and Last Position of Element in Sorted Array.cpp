class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0) return {-1, -1}; 
        auto a = lower_bound(nums.begin(), nums.end(), target), b = upper_bound(nums.begin(), nums.end(), target) - 1;
        if(a == nums.end() || *a != target) return {-1, -1};  // first part = everything is less than || target not in nums
        
        return {int(a - nums.begin()), int(b - nums.begin())};
    }
};
