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
/*
Runtime: 6 ms, faster than 11.99% of Java online submissions for Is Graph Bipartite?.
Memory Usage: 45.5 MB, less than 52.24% of Java online submissions for Is Graph Bipartite?.
*/

class SolutionDFS {
    int N;
    int[] parts;
    int[][] graph;
    public boolean isBipartite(int[][] g) {
        N = g.length;
        parts = new int[N];
        graph = g;
        for (int i = 0; i != N; i++)
            if (parts[i] == 0 && !helper(i, 1)) return false; //only calls helper if unvisited
        return true; //must all return true, so if one false, we return false
    }

    public boolean helper(int ind, int pt) {
        if (parts[ind] == 3 - pt) return false; //wrong part
        if (parts[ind] == pt) return true; //already visited
        parts[ind] = pt;
        for (int n: graph[ind])
            if (!helper(n, 3 - pt)) return false;
        return true;
    }
}
/*
Runtime: 0 ms, faster than 100.00% of Java online submissions for Is Graph Bipartite?.
Memory Usage: 44.1 MB, less than 71.81% of Java online submissions for Is Graph Bipartite?.
*/
