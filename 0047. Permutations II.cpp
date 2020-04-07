class Solution {
public:
    vector<vector<int>> res;
    
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        res.clear();
        help(nums, 0);
        return res;
    }
    
    void help(vector<int>& nums, int i){
        int N = nums.size();
        if(i == N){
            res.push_back(nums);
            return;
        }
        unordered_set<int> used;    // track what numbers we've put in position i
        for(int j = i; j != N; ++j){    // try one with out swapping
            if(used.count(nums[j])) continue;
            used.insert(nums[j]);
            swap(nums[i], nums[j]);
            help(nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }
};
