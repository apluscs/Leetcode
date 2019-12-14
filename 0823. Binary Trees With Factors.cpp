class Solution {
    public:
        int numFactoredBinaryTrees(vector < int > & A) {
            sort(A.begin(), A.end());
            unordered_map < int, long > dp;
            unordered_set < int > s;

            for (int a: A) {
                s.insert(a);
                dp[a]++; //one tree of each num by itself
            }

            long total = 1;
            int mod = 1e9 + 7;
            vector < int > nums = A;
            for (int i = 1; i < A.size(); i++) {
                for (int j = 0; j < i; j++) { //search thru all smaller nums
                    if (nums[i] % nums[j] == 0 && s.find(nums[i] / nums[j]) != s.end()) { //if we found a factor and its partner
                        dp[nums[i]] += dp[nums[j]] * dp[nums[i] / nums[j]]; //#ways to make LHS * #ways to make RHS
                        dp[nums[i]] %= mod;
                    }
                }
                total += dp[nums[i]];
                total %= mod;
            }
            return static_cast < int > (total);
        }
};
