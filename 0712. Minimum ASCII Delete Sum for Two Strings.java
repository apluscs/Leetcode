class Solution {
    public int minimumDeleteSum(String s1, String s2) {
        int N = s1.length(), M = s2.length();
        int[][] dp = new int[N + 1][M + 1];
        for (int j = 1; j != M + 1; j++) dp[0][j] = dp[0][j - 1] + s2.codePointAt(j - 1); //cummul. sum
        for (int i = 1; i != N + 1; i++) dp[i][0] = dp[i - 1][0] + s1.codePointAt(i - 1); //same for s1
        for (int i = 1; i != N + 1; i++)
            for (int j = 1; j != M + 1; j++) {
                if (s1.charAt(i - 1) == s2.charAt(j - 1)) dp[i][j] = dp[i - 1][j - 1]; //these chars are perfect match = no cost
                else dp[i][j] = Math.min(dp[i - 1][j] + s1.codePointAt(i - 1), dp[i][j - 1] + s2.codePointAt(j - 1)); //need to delete either s1[i-1] or s2[j-1]; choose whichever yields less cost
            }
        // for(int[] d:dp) System.out.println(Arrays.toString(d));
        return dp[N][M];
    }
}
