class Solution {
    public:
        int lengthOfLIS(vector < int > & nums) {
            int res = 0, N = nums.size();
            vector < int > dp(N); // maintain LIS (cummulative)
            for (int num: nums) {
                int i = bSearch(dp, 0, res, num);
                dp[i] = num;
                if (i == res) res++; // num is greater than all in dp, so we can lengthen LIS
            }
            return res;
        }

    int bSearch(vector < int > & nums, int low, int high, int target) {
        while (low < high) { // search for target
            int mid = (low + high) >> 1;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) high = mid;
            else low = mid + 1;
        } // if not found, return where it's supposed to be (error up - this way, target num will displace the higher num instead of the lower
        // one, allowing for a smaller-valued LIS)
        return low;
    }
};
