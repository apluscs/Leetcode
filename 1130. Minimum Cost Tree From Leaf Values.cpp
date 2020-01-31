class Solution {
  public:
    int mctFromLeafValues(vector < int > & arr) {
      int N = arr.size();
      vector < vector < int >> max_leaf(N, vector < int > (N)), dp(N, vector < int > (N));
      for (int i = 0; i != N; ++i) {
        int curr = 0;
        for (int j = i; j != N; ++j) {
          curr = max(curr, arr[j]);
          max_leaf[i][j] = curr; //max_leaf[i][j] = largest leaf from indexes i and j, inclusive
        }
      }

      for (int gap = 1; gap != N; ++gap)
        for (int i = 0; i + gap != N; ++i) {
          int j = i + gap, res = INT_MAX;
          for (int k = i; k < j; ++k) { // try all possible splitting points
            int curr = dp[i][k] + dp[k + 1][j] + max_leaf[i][k] * max_leaf[k + 1][j];
            res = min(res, curr); // sum of non-leaves in LHS + sum of non-leaves in RHS + value of new root (product of largest max_leaves on LHS and RHS)
          }
          dp[i][j] = res;
        }
      return dp[0][N - 1];
    }
};
