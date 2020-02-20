class Solution {
  public:
    int jump(vector < int > & nums) {
      int N = nums.size(), res = 0, currEnd = 0, nextEnd = 0;
      for (int i = 0; i != N - 1; ++i) { // don't count last jump to the end
        nextEnd = max(nextEnd, i + nums[i]); // farthest you could go
        if (i == currEnd) { // done traversing all in your range
          currEnd = nextEnd; // pretend you jumped at i when i+nums[i] updated nextEnd
          res++; // you jumped
        }
      }
      return res;
    }
};
