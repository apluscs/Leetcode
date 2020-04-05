class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int sum = 0, N = nums.size(), curr = 0, res = -1;
        for(int num : nums) sum += num;
        for(int i = 0; i != N; ++i){
            curr += nums[i];
            if(curr > sum / 2){
                res = i;
                break;
            }
        }
        return vector<int>(nums.begin(), nums.begin() + res + 1);
    }
};
