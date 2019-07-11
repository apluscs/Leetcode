class Solution {
    public double largestSumOfAverages(int[] A, int K) {
        int N = A.length;
        double[][] dp = new double[K][N]; //memory 
        double[] sum = new double[N];
        sum[0] = dp[0][0] = (double) A[0];
        for (int i = 1; i != N; i++) {
            sum[i] = sum[i - 1] + A[i];
            dp[0][i] = sum[i] / (i + 1); //dp[0]=max answer for subarray from 0 to i, using at most (i+1) groups, at least 1 group
        }
        for (int i = 1; i != K; i++) {
            dp[i][0] = A[0]; //first col is always the same
            for (int j = 1; j != N; j++)
                for (int k = 0; k != j; k++) //we know dp[i-1] uses one less partition than dp[i], so we try partitioning the subarray from 0 to j at each possible point
                    dp[i][j] = Math.max(dp[i][j], dp[i - 1][k] + (sum[j] - sum[k]) / (j - k)); //new average would be old average from 0 to k + average of the subarray to the right
            // System.out.println(Arrays.toString(dp[i]));
        }
        // System.out.println(Arrays.toString(sum));

        return dp[K - 1][N - 1];
    }
}
/*
Runtime: 7 ms
Memory Usage: 34.6 MB
*/

class Solution {
    public double largestSumOfAverages(int[] A, int K) {
        int N = A.length;
        double[] prev = new double[N];  //only use one array at a time
        double[] sum = new double[N];
        sum[0] = prev[0] = (double) A[0];
        for (int i = 1; i != N; i++) {
            sum[i] = sum[i - 1] + A[i];
            prev[i] = sum[i] / (i + 1); 
        }
        for (int i = 1; i != K; i++) {
            double[] curr = new double[N];
            curr[0] = A[0]; //first col is always the same
            for (int j = 1; j != N; j++)
                for (int k = 0; k != j; k++)
                    curr[j] = Math.max(curr[j], prev[k] + (sum[j] - sum[k]) / (j - k));
            // System.out.println(Arrays.toString(curr));
            prev = curr;
        }
        // System.out.println(Arrays.toString(sum));

        return prev[N - 1];
    }
}
/*
Runtime: 6 ms, faster than 52.72% of Java online submissions for Largest Sum of Averages.
Memory Usage: 34.8 MB, less than 100.00% of Java online submissions for Largest Sum of Averages.
*/
