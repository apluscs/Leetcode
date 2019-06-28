class Solution {
    int N;
    List < List < Integer >> res;
    int[][] graph;
    public List < List < Integer >> allPathsSourceTarget(int[][] g) { //classic dfs
        N = g.length;
        graph = g;
        res = new LinkedList < > ();
        helper(new LinkedList < > (), 0);
        return res;
    }
    void helper(LinkedList < Integer > curr, int nd) { //must have linked here to use methods
        curr.add(nd);
        if (nd == N - 1) res.add(new LinkedList < > (curr)); //must be a copy
        for (int j: graph[nd]) helper(curr, j);
        curr.removeLast();
    }
}
