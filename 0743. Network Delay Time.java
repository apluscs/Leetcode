class Solution {
    public int networkDelayTime(int[][] times, int N, int K) {
        int[][] adj = new int[N + 1][N + 1]; //adj[i][j]=time from i to j
        for (int[] ad: adj) Arrays.fill(ad, -1); //cannot keep as 0 in case there is an edge 0
        for (int[] t: times) adj[t[0]][t[1]] = t[2];
        PriorityQueue < int[] > toVis = new PriorityQueue < int[] > ((a, b) - > a[1] - b[1]);
        int[] vis = new int[N + 1]; //keeps track of min time to [i] from source
        Arrays.fill(vis, -1);
        int res = -1;
        toVis.add(new int[] {
            K,
            0
        });
        while (!toVis.isEmpty()) {
            int[] arr = toVis.poll();
            int curr = arr[0];
            if (vis[curr] != -1) continue; //needed - to override past additions into PQ  that are larger and thus obsolete now
            // System.out.println(Arrays.toString(arr));
            vis[curr] = arr[1];
            for (int i = 1; i != N + 1; i++) {
                if (adj[curr][i] != -1 && vis[i] == -1) { //checking visited status here is not needed but helpful
                    toVis.add(new int[] {
                        i,
                        adj[curr][i] + arr[1]
                    });
                }
            }
        }
        for (int i = 1; i != N + 1; i++) {
            if (vis[i] == -1) return -1;
            res = Math.max(res, vis[i]);
            // System.out.println(i+", "+vis[i]);
        }
        return res;
    }
}
