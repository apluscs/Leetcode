class Solution { //NOT DONE
    HashSet < Integer > [] adj;
    int[] count, res;
    int N;
    public int[] sumOfDistancesInTree(int N, int[][] edges) {
        adj = new HashSet[N];
        this.N = N;
        count = new int[N];
        res = new int[N];
        for (int i = 0; i != N; i++) adj[i] = new HashSet < Integer > ();
        for (int[] e: edges) {
            adj[e[0]].add(e[1]);
            adj[e[1]].add(e[0]);
        }
        countUp(0, -1); //count[i]=# nodes below and including this node
        // System.out.println(Arrays.toString(count));
        // System.out.println(Arrays.toString(res));
        resUp(0, -1); //after countUp(), res[0] is final
        return res;
    }

    public void countUp(int curr, int par) {
        count[curr] = 1; //count yourself
        for (int nei: adj[curr]) {
            if (nei == par) continue;
            countUp(nei, curr);
            count[curr] += count[nei]; //add however many are below you
            res[curr] += res[nei] + count[nei]; //basically the answer except with only those below you
        }
    }

    public void resUp(int curr, int par) {
        if (par != -1) {
            res[curr] = res[par] - count[curr] + N - count[curr];
            //res[par]=sum[curr]+count[curr]+sum[other kids]+count[other half of tree]. 
            //The nodes under curr are count[curr] steps closer, but the ones not under curr are N-count[curr] (all other nodes) steps farther
        }
        for (int nei: adj[curr]) {
            if (nei == par) continue;
            resUp(nei, curr);
        }
    }
}
