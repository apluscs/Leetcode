class Solution {
  public:
    double findMaxAverage(vector < int > & nums, int k) {
      int sum = 0, res = INT_MIN, N = nums.size(), i = 0, j = 0; //i is start; j is end
      for (; j != k; ++j) sum += nums[j]; // get first k nums
      for (; j != N; ++i, ++j) {
        res = max(res, sum);
        sum = sum - nums[i] + nums[j];
      }
      res = max(res, sum); // last k never got counted
      return (double) res / k;
    }
};
