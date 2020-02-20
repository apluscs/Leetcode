class Solution: # faster than version below
    def canJump(self, nums: List[int]) -> bool:
        N = len(nums)
        closest = N-1   # minimum index that is able to reach the end
        for i in range(N-2, -1, -1):
            if closest - i <= nums[i]:  # can jump to something than reaches the end
                closest = i
        return closest == 0


/*
class Solution {  // a bit slower
  public:
    bool canJump(vector < int > & nums) {
      int N = nums.size();
      nums[N - 1] = -1; // mark as reachable
      for (int i = N - 2; i > -1; --i)
        for (int j = i + 1; j <= i + nums[i]; ++j) // see if anything within your span is reachable
          if (nums[j] == -1) {
            nums[i] = -1;
            break;
          }
      return nums[0] == -1;
    }
};
*/
