class Solution {
    public int findLength(int[] A, int[] B) {
        int[][] dp = new int[A.length + 1][B.length + 1];
        int res = 0;
        for (int i = 1; i != A.length + 1; i++)
            for (int j = 1; j != B.length + 1; j++)
                if (A[i - 1] == B[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    res = Math.max(res, dp[i][j]);
                }
        return res;
    }
}

class Solution {  //faster, less memory
    public int findLength(int[] A, int[] B) {
        int[] prev = new int[B.length + 1];
        int res = 0;
        for (int i = 0; i != A.length; i++) {
            int[] curr = new int[B.length + 1]; //only need the previous row, can ignore everything before that
            for (int j = 0; j != B.length; j++)
                if (A[i] == B[j]) { //found one more num repeated
                    curr[j + 1] = prev[j] + 1;
                    res = Math.max(curr[j + 1], res);
                }
            prev = curr;
        }
        return res;
    }
}
