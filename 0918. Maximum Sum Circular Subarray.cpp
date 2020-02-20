class Solution {
  public:
    int maxSubarraySumCircular(vector < int > & nums) {
      int N = nums.size(), curr = nums[0], res = curr; //curr = max subarray sum ending at i    
      vector < int > before(N), after(N);

      before[0] = curr;
      for (int i = 1; i != N; ++i) {
        curr += nums[i]; // cumm sum
        before[i] = max(before[i - 1], curr); // max subarray from 0 ending <= i
      }

      curr = after[N - 1] = nums[N - 1];
      for (int i = N - 2; i > -1; --i) {
        curr += nums[i];
        after[i] = max(after[i + 1], curr); // max subarray ending at N-1, starting >= i
      }

      curr = 0;
      for (int i = 0; i != N; ++i) {
        curr = max(0, curr) + nums[i]; // largest subarray ending at i (from LC #53)
        int prior = i == 0 ? 0 : before[i - 1]; // now try to connect pieces, prior = largest subarray that touches the front and falls before i 
        int later = after[i]; // largest that touches the end and falls >= i
        res = max(res, max(curr, later + prior)); // three choices
      }
      return res;
    }
};
