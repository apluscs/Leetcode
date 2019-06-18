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
