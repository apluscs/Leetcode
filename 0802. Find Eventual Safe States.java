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
