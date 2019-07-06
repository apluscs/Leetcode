class Solution {

    public List < Integer > eventualSafeNodes(int[][] graph) {
        int N = graph.length;
        boolean[] res = new boolean[N];
        HashSet < Integer > [] rg = new HashSet[N];
        int[] c = new int[N];
        Queue < Integer > que = new LinkedList < > ();
        for (int i = 0; i != N; i++) rg[i] = new HashSet < Integer > ();
        for (int i = 0; i != N; i++) {
            for (int j: graph[i]) {
                rg[j].add(i); //edge from i leads to j
                c[i]++; //#outgoing edges from i
            }
            if (c[i] == 0) que.add(i);
            // System.out.println(c[i]);
        }
        while (!que.isEmpty()) {
            int curr = que.poll();
            res[curr] = true;
            for (Integer i: rg[curr]) { //process all nodes that direct to curr
                c[i]--; //don't need to remove edge from graph, only need to track # of out edges
                if (c[i] == 0) que.add(i);
            }
            rg[curr].clear(); //remove edge from i to curr
        }
        List < Integer > rs = new ArrayList < > ();
        for (int i = 0; i != N; i++)
            if (res[i]) rs.add(i);
        return rs;
    }
}


class SolutionFast {
    int[] vis;
    int[][] graph;
    public List < Integer > eventualSafeNodes(int[][] g) {
        vis = new int[g.length];
        graph = g;
        List < Integer > res = new ArrayList < > ();
        for (int i = 0; i != graph.length; i++)
            if (dfs(i)) res.add(i);
        return res;
    }

    boolean dfs(int curr) { //objective is to try to find one path to a cycle=bad node
        if (vis[curr] == 1) return false; //node we alr visited in this path = cycle OR a node that has been marked as a cycle previously
        if (vis[curr] == 2) return true; //we know this node is good so don't worry
        vis[curr] = 1; //mark as cycle
        for (int ng: graph[curr])
            if (!dfs(ng))
                return false;
        vis[curr] = 2; //only demark cycle if we make it past the for loop(good node)
        return true;
    }
}
