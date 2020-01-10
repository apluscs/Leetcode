class Solution {
  public:
    bool checkPossibility(vector < int > & nums) {
      int N = nums.size(), res = 0;
      for (int i = 1; i != N; i++) {
        if (nums[i] >= nums[i - 1]) continue;
        if (i < 2 || nums[i - 2] <= nums[i]) nums[i - 1] = nums[i]; // imagine nums beginning with -INF, better to change nums[i-1] than increase nums[i]
        else nums[i] = nums[i - 1]; // increase as little as possible
        res++;
      }
      return res <= 1;
    }
};
