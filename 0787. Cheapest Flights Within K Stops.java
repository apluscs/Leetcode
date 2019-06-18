class Solution {
    public int findCheapestPrice(int N, int[][] flights, int src, int des, int K) {
        int[][] adj = new int[N][N];
        for (int[] f: flights) adj[f[0]][f[1]] = f[2];
        PriorityQueue < int[] > pq = new PriorityQueue < > ((a, b) - > a[1] - b[1]);
        pq.add(new int[] { src, 0, 0 }); //landing site, total dist to here, #stops used
        while (!pq.isEmpty()) {
            int[] arr = pq.poll();
            // System.out.println(Arrays.toString(arr));
            if (arr[0] == des) return arr[1];
            if (arr[2] == K + 1) continue; //cannot make any more stops, 0..(1-K stops) K+1th is dest

            int curr = arr[0];
            for (int n = 0; n != N; n++)
                if (adj[curr][n] != 0) pq.add(new int[] { n, adj[curr][n] + arr[1], arr[2] + 1 });
        }
        return -1;
    }
}

class SolutionDP {
    public int findCheapestPrice(int N, int[][] flights, int src, int des, int K) {
        long[][] dp = new long[K + 2][N]; //dp[i][j]=cheapest price to get to city j using i-1 stops
        for (long[] d: dp) Arrays.fill(d, Integer.MAX_VALUE);
        dp[0][src] = 0; //row 0 is infinite except for src
        for (int i = 1; i != K + 2; i++) { //rows are shifted down 1 to avoid index bound exception (i-1)
            dp[i][src] = 0; //no cost to stay put
            for (int[] f: flights) dp[i][f[1]] = Math.min(dp[i][f[1]], dp[i - 1][f[0]] + f[2]); //price to get to departure city f[0] + price of flight to city f[1]
            // System.out.println(Arrays.toString(dp[i]));
        }
        return dp[K + 1][des] == Integer.MAX_VALUE ? -1 : (int) dp[K + 1][des];
    }
}

class SolutionDP2 { //better memory by only keeping 2 dp[] at a time
    public int findCheapestPrice(int N, int[][] flights, int src, int des, int K) {
        long[] prev = new long[N];
        Arrays.fill(prev, Integer.MAX_VALUE);
        prev[src] = 0;
        for (int i = 0; i != K + 1; i++) {
            long[] curr = new long[N];
            Arrays.fill(curr, Integer.MAX_VALUE);
            curr[src] = 0;
            for (int[] f: flights) curr[f[1]] = Math.min(curr[f[1]], prev[f[0]] + f[2]); //price to get to departure city f[0] + price of flight to city f[1]
            // System.out.println(Arrays.toString(curr));
            prev = curr;
        }
        return prev[des] == Integer.MAX_VALUE ? -1 : (int) prev[des];
    }
}
