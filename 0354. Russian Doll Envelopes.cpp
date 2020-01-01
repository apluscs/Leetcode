class Solution {
    public:
        static bool Compar(const vector < int > & a,
            const vector < int > & b) {
            return a[0] != b[0] ? a[0] < b[0] : a[1] > b[1];
        } // note: these things need to be static, parameters need to be const

    int maxEnvelopes(vector < vector < int >> & evs) {
        int N = evs.size(), res = 0;
        sort(evs.begin(), evs.end(), Compar); // ascending width, descending height
        vector < int > dp(N);
        for (int i = 0; i != N; i++) { // LIS
            vector < int > curr = evs[i];
            int j = lower_bound(dp.begin(), dp.begin() + res, curr[1]) - dp.begin();
            dp[j] = curr[1]; // 
            if (j == res) res++;
        }
        return res;
    }
};
