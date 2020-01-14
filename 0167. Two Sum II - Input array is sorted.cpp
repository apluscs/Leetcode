class Solution {
  public:
    vector < int > twoSum(vector < int > & nums, int target) {
      int i = 0, N = nums.size(), j = N - 1;
      while (i < j) {
        while (i < j && nums[i] + nums[j] > target) j--;
        if (i < j && nums[i] + nums[j] == target) return {
          1 + i,
          1 + j
        }; // now j is the greatest j such that nums[i]+nums[j] <= target
        i++; // move on to next, we can eliminate beyond j because if those were too big for a smaller i, they'd be too big for this next i
      }
      return {};
    }
};
