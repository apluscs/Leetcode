class Solution {
    final int[][] ops = { { 4, 0 }, { 3, 1 }, { 2, 2 }, { 1, 3 } };
    public double soupServings(int N) {
        if (N >= 5000) return 1;
        N = N / 25 + (N % 25 == 0 ? 0 : 1); 
        //40 mL gives same result as 50 mL because in both cases, fluids will run out at the same time! 
        //(ex. if you have 15mL or 25mL, you will run out if you need to serve >=25mL)
        double[][] dp = new double[N + 1][N + 1];
        Arrays.fill(dp[0], 1);
        dp[0][0] = 0.5; //case in which run out at the same time  -> *.5
        for (int a = 1; a != N + 1; a++)
            for (int b = 1; b != N + 1; b++) {
                for (int[] op: ops) //if you don't have enough (neg index), then you "ran out" = look at 0
                    dp[a][b] += dp[Math.max(a - op[0], 0)][Math.max(b - op[1], 0)];
                dp[a][b] *= 0.25; //25% prob of getting each of the four ops
            }
        // for(double[] d:dp) System.out.println(Arrays.toString(d));
        return dp[N][N];
    }
}
