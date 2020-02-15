class Solution {
  public:
    int minDifficulty(vector < int > & jobs, int D) {
      int M = jobs.size();
      if (M < D) return -1;
      vector < vector < int >> dp(D, vector < int > (M)); // top row is 0
      int mx = 0;
      for (int j = 0; j != M; ++j) { // first row is cummulative maximum
        mx = max(jobs[j], mx);
        dp[0][j] = mx;
      }
      for (int i = 1; i != D; ++i) {
        for (int j = i; j != M; ++j) {
          mx = 0;
          int res = INT_MAX;
          for (int k = j; k >= i; --k) { // last one is dp[i-1][j]
            mx = max(mx, jobs[k]); // max of jobs to do TODAY
            res = min(res, dp[i - 1][k - 1] + mx); // difficulty for today + how much difficulty if you had one less day 
            // and did k-1 jobs
          }
          dp[i][j] = res;
        }
      }
      return dp[D - 1][M - 1];
    }
};
