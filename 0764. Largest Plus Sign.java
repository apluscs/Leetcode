class Solution {
    public int orderOfLargestPlusSign(int N, int[][] mines) {
        int[][] grid = new int[N][N], dp = new int[N][N];
        int res = 0;
        for (int i = mines.length - 1; i != -1; i--) grid[mines[i][0]][mines[i][1]] = -1; //mark as bad
        for (int[] d: dp) Arrays.fill(d, 1);
        for (int i = 0; i != N; i++) {
            for (int j = 0; j != N; j++) //left arm length (including center cell)
                dp[i][j] = grid[i][j] == -1 ? 0 : (j == 0 ? 1 : dp[i][j - 1] + 1);
            int chain = 0;
            // print(dp);
            for (int j = N - 1; j != -1; j--) { //right arm length
                chain = grid[i][j] == -1 ? 0 : chain + 1;
                dp[i][j] = Math.min(dp[i][j], chain);
            }
            // print(dp);
        }
        for (int j = 0; j != N; j++) { //upper arm length
            int chain = 0;
            for (int i = 0; i != N; i++) {
                chain = grid[i][j] == -1 ? 0 : chain + 1;
                dp[i][j] = Math.min(dp[i][j], chain);
            }
            chain = 0;
            for (int i = N - 1; i != -1; i--) { //bottom arm length
                chain = grid[i][j] == -1 ? 0 : chain + 1;
                dp[i][j] = Math.min(dp[i][j], chain);
                res = Math.max(res, dp[i][j]); //last time we are modifying this cell, so we can consider it final
            }
            // print(dp);
        }
        return res;
    }

    public void print(int[][] nums) {
        for (int[] n: nums) System.out.println(Arrays.toString(n));
        System.out.println();
    }
}
