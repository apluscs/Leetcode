class Solution {
    final static int MOD = 1000000007;
    public int numTilings(int N) {
        if (N < 3) return N;
        long[][] dp = new long[2][N + 1]; //top row=figure with j complete columns 1 half column; bottom row=j+1 complete columns
        dp[0][1] = dp[1][0] = 1;
        dp[1][1] = dp[0][2] = 2;
        dp[1][2] = 5; //initial vals
        for (int j = 2; j <= N; j++) {
            dp[0][j] = dp[1][j - 2] + dp[0][j - 1]; //tromino on right side? horz domino on top row?
            dp[1][j] = dp[1][j - 2] + dp[1][j - 1] + 2 * dp[0][j - 1]; //vert domino? horz domino (must have two of these stacked)? tromino(2 orientations)?
            dp[1][j] %= MOD;
        }
        // System.out.println(Arrays.toString(dp[0]));
        // System.out.println(Arrays.toString(dp[1]));
        return (int) dp[1][N - 1];
    }
}
