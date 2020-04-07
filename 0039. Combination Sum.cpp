class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        res.clear();
        vector<int> curr;
        sort(nums.begin(), nums.end()); // sorting optimizations didn't rlly help
        help(nums, curr, target);
        return res;
    }
    
    void help(vector<int>& nums, vector<int>& curr, int target){
        if(target == 0){
            res.push_back(curr);
            return;
        }
        for(auto it = curr.empty() ? nums.begin() : lower_bound(nums.begin(), nums.end(), curr.back()); it != nums.end() && *it <= target; ++it){
            
            int num = *it;
            curr.push_back(num);
            help(nums, curr, target - num);
            curr.pop_back();
        }
    }
};
