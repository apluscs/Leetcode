class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) {
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
        for(int j = i; j != N; ++j){    // try one with out swapping
            swap(nums[i], nums[j]);
            help(nums, i + 1);
            swap(nums[i], nums[j]);
        }
    }
};
