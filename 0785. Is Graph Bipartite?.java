class Solution {
    public boolean isBipartite(int[][] graph) {
        int N = graph.length;
        int[] parts = new int[N];
        for (int i = 0; i != N; i++) {
            if (parts[i] != 0) continue; //already processed
            Queue < int[] > que = new LinkedList < > ();
            que.add(new int[] { i, 1 }); //if no restrictions on what part it needs to be in, just place in in part 1
            while (!que.isEmpty()) {
                int[] arr = que.poll();
                int curr = arr[0];
                if (parts[curr] == 3 - arr[1]) return false; //what it should NOT be
                else if (parts[curr] == arr[1]) continue; //already processed this node
                parts[curr] = arr[1];
                for (int n: graph[curr]) que.add(new int[] { n, 3 - arr[1] }); //all neighbors should be on the opposite part
            }
        }
        return true;
    }
}
