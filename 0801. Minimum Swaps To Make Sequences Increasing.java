class Solution {
    public int minSwap(int[] A, int[] B) {
        int N = A.length;
        //nn=no swap [i] from nonswapped[i-1], ns=no swap[i] from swapped[i-1]
        //ss=swap[i] from swapped[i-1], sn=swap[i] from non swapped[i-1]
        int[][] dp = new int[2][N];
        dp[1][0] = 1; //dp[0][i] tracks min #swaps if we did NOT swap i, dp[1][i] tracks # if we did
        for (int i = 1; i != N; i++) {
            int nn = 1001, ns = 1001, sn = 1001, ss = 1001;
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
                nn = dp[0][i - 1];
                ss = dp[1][i - 1] + 1;
            }
            if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
                ns = dp[1][i - 1];
                sn = dp[0][i - 1] + 1; //ss and sn requires us to add one more swap
            }
            dp[0][i] = Math.min(ns, nn);
            dp[1][i] = Math.min(sn, ss);
        }
        // System.out.println(Arrays.toString(dp[0]));
        // System.out.println(Arrays.toString(dp[1]));
        return Math.min(dp[0][N - 1], dp[1][N - 1]);
    }
}
