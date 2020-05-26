class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        res.clear();
        vector<int> curr;
        sort(nums.begin(), nums.end());
        help(nums, curr, target, 0);
        return res;
    }
    
    void help(vector<int>& nums, vector<int>& curr, int target, int start){
        if(target == 0){
            res.push_back(curr);
            return;
        }
        for(int i = start; i != nums.size(); ++i){
            if(nums[i] > target || i != start && nums[i] == nums[i-1]) continue;`// already put the value nums[i] in curr
            curr.push_back(nums[i]);
            help(nums, curr, target - nums[i], i + 1);
            curr.pop_back();
        }
    }
};
