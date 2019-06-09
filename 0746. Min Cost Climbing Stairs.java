class SolutionMem { //less memory usage
    public int minCostClimbingStairs(int[] cost) {
        int N = cost.length;
        int p2 = cost[0], p1 = cost[1]; //only need to save the prev two cells, do not need the entire dp array
        for (int i = 2; i != N; i++) { //dp[i]=min cost if i were the last cell
            int curr = Math.min(p1, p2) + cost[i];
            p2 = p1;
            p1 = curr;
        }
        return Math.min(p1, p2);
    }
}

class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int N = cost.length;
        int[] dp = new int[N];
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i != N; i++) { //dp[i]=min cost if i were the last cell
            dp[i] = Math.min(dp[i - 1], dp[i - 2]) + cost[i]; //come from two steps ago? or just one?
        }
    }
    return Math.min(dp[N - 1], dp[N - 2]);
}
