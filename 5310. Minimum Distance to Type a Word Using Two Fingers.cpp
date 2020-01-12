class Solution {
  public:
    int minimumDistance(string str) {
      int N = str.length(), res = INT_MAX;
      // each index in str gets a 26 x 26 grid
      vector < vector < vector < int >>> dp(N + 1, vector < vector < int >> (26, vector < int > (26))); // dp[N] is all-zero, everything has no cost
      for (int i = N - 1; i != -1; --i)
        for (int a = 0; a != 26; a++) // first finger
          for (int b = 0; b != 26; b++) { // second finger
            int c = str[i] - 'A'; // curr character
            dp[i][a][b] = min(cost(a, c) + dp[i + 1][c][b], cost(b, c) + dp[i + 1][a][c]);
            // move finger1 to c and see how much cost with the rest of the str, finger1 starting at c and finger2 not changing
            // OR move finger2 to c and see how much cost with the rest of the str, finger2 starting at c and finger1 not changing
            if (i == 0)
              res = min(res, dp[i][a][b]);
          }
      return res;
    }

  int cost(int i, int j) { // // i/6 is row, i%6 is column
    return abs(i / 6 - j / 6) + abs(i % 6 - j % 6); // manhattan distance
  }
};
