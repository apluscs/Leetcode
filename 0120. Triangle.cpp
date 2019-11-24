class Solution {
    public:
        int minimumTotal(vector < vector < int >> & triangle) {
            int N = triangle.size(), res = INT_MAX;
            if (N == 0 || triangle[0].size() == 0) return 0;
            vector < int > prev(N), curr(N);
            prev[0] = triangle[0][0];
            for (int rd = 1; rd != N; rd++) {
                for (int i = 0; i <= rd; i++) {
                    int op1 = i == 0 ? 1e9 : prev[i - 1], //choose left/up option, if you can
                        op2 = i == rd ? 1e9 : prev[i]; //chose right/up option, if you can
                    curr[i] = triangle[rd][i] + min(op1, op2);
                    // cout<<curr[i]<<" ";
                }
                prev = curr;
                // cout<<endl;
            }
            for (int i = 0; i != N; i++) res = min(res, prev[i]);
            return res;
        }
};
