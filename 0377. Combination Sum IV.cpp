class Solution {
    public:
        int combinationSum4(vector < int > & nums, int target) {

            vector < unsigned int > dp(target + 1); //why does this work? long long doesn't work!
            dp[0] = 1; //1 way to make a sum of zero
            for (int i = 1; i != target + 1; i++)
                for (int lhs: nums) {
                    if (lhs > i) continue; //next line would be invalid
                    dp[i] += dp[i - lhs]; // #ways to make LHS = 1 * #ways to make RHS (subtarget-lhs)
                }
            return dp[target];
        }
};
