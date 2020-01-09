class Solution {
  public:
    int findLengthOfLCIS(vector < int > & nums) {
      int res = 1, N = nums.size();
      if (N == 0) return 0;
      for (int i = 0, j = 1; j != N; j++) { // i marks start of chain
        if (nums[j - 1] >= nums[j]) i = j; // new start
        res = max(res, j + 1 - i); // j+1 is the 1 past the "end"
      }
      return res;
    }
};
