class Solution { //basically copied from discussion cuz I was sick and lazy, do again
    public double new21Game(int N, int K, int W) {
        double[] dp = new double[N + 1];
        if (K == 0 || N >= K + W) return 1;
        double res = 0, sum = 1;
        dp[0] = 1;
        for (int i = 1; i <= N; i++) {
            dp[i] = sum / W;
            if (i < K) sum += dp[i];
            else res += dp[i];
            if (i - W >= 0) sum -= dp[i - W];
        }
        return res;
    }
}

class Solution { //TLE
    public double new21Game(int N, int K, int W) {
        double[] prev = new double[K];
        double[] res = new double[N + 1];
        for (int i = 1; i <= W && i < K; i++) prev[i] = 1.0 / W;
        for (int i = K; i <= W && i <= N; i++) res[i] = 1.0 / W;
        if (K == 0) return 1;
        for (int rd = 0; rd != K; rd++) { //last the longest if you draw a 1 every time
            double[] curr = new double[K];
            for (int i = 1; i != K; i++) //for each probability in prev round
                for (int j = 1; j <= W; j++)
                    if (i + j < K) curr[i + j] += prev[i] / W; //adding to probability of [i+j] in current round
                    else if (i + j <= N) {
                res[i + j] += prev[i] / W; //track this in res
                // System.out.println(prev[i]/W);
            }

            prev = curr;
            // System.out.println(Arrays.toString(curr));
        }
        double sum = 0;
        // System.out.println(Arrays.toString(res));
        for (int i = N; i != K - 1; i--) sum += res[i];
        return sum;
    }
}
