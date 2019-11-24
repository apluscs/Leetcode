class Solution {
    public:
        int maxProfit(vector < int > & prices) {
            int res = 0, mini = INT_MAX, N = prices.size();
            for (int i = 0; i != N; i++) {
                mini = min(mini, prices[i]);
                res = max(res, prices[i] - mini);
            }
            return res;
        }
};
