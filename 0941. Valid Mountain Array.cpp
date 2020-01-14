class Solution {
  public:
    bool validMountainArray(vector < int > & nums) {
      int i = 1, N = nums.size();
      if (N < 3) return false;
      for (; i != N - 1; ++i) {
        if (nums[i - 1] == nums[i]) return false; // strictly ascend
        if (nums[i - 1] > nums[i]) break; // now at the peak +1   
      }
      if (i == 1) return false; // never ascended
      for (; i != N; ++i)
        if (nums[i - 1] <= nums[i]) return false; // should only descend
      return true;
    }
};
