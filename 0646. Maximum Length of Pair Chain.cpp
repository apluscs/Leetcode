class Solution {
    public:

        static bool compar(const vector < int > & a,
            const vector < int > & b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] < b[1];
        }

    int findLongestChain(vector < vector < int >> & nums) {
        sort(nums.begin(), nums.end(), compar); // sort by start time
        int N = nums.size();
        vector < int > dp(N);
        for (int i = 0; i != N; ++i) {
            int j = helper(nums[i][0], i, nums); // latest compatible pair
            dp[i] = j == -1 ? 1 : dp[j] + 1; // if none, dp[i] = just itself
        }
        return dp[N - 1];

    }

    int helper(int start, int i, vector < vector < int >> & nums) { // find latest starting pair
        for (int j = i - 1; j != -1; --j) // that ends before nums[i] start
            if (nums[j][1] < start) return j;
        return -1;
    }
};
