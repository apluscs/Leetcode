class Solution {
public:
    string stoneGameIII(vector<int>& nums) {
        int diff = 0, N = nums.size();
        vector<int> dp(N + 3);
        nums.resize(N + 3);
        for(int i = N - 1; i != -1; --i){
            int a = nums[i] - dp[i + 1];    // taking first one only
            // your 'revenue' = your profit from this - partner's 'revenue' from the rest
            int b = nums[i] + nums[i + 1] - dp[i + 2];  // taking first and second
            int c = nums[i] + nums[i + 1] + nums[i + 2] - dp[i + 3];    // take all 3
            dp[i] = max(a, max(b, c));
        }
        int k = dp[0];
        if(k > 0) return "Alice";   // alice able to make positive revenue
        if(k == 0) return "Tie";
        return "Bob";
    }
    
};
