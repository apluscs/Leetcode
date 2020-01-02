class Solution {
    public:
        vector < vector < int >> findSubsequences(vector < int > & nums) {
            int N = nums.size(); // dp[i] = all IS that end at i
            vector < vector < vector < int >>> dp(N);
            vector < vector < int >> res;
            for (int i = 0; i != N; i++) {
                bool dup = false;
                for (int j = i - 1; !dup && j != -1; --j) {
                    if (nums[j] == nums[i]) dup = true;
                    if (nums[j] > nums[i]) continue; // cannot form an IS with j
                    for (vector < int > curr: dp[j]) { // all are compatible with i
                        curr.push_back(nums[i]); // extend it
                        dp[i].push_back(curr); // store it
                        res.push_back(curr); // in final answer too
                    }
                }
                if (!dup) dp[i].push_back({ nums[i] }); // dont wanna push back {7} twice ya know?
            }
            return res;
        }
};
