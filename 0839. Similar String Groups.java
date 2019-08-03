/*Runtime: 805 ms, faster than 13.15% of Java online submissions for Similar String Groups.
Memory Usage: 313.2 MB, less than 5.13% of Java online submissions for Similar String Groups.*/

class Solution { 
    HashSet < Integer > [] adj;
    int[] gr;
    boolean[] vis;
    public int numSimilarGroups(String[] A) {
        int N = A.length, res = 0;
        adj = new HashSet[N];
        gr = new int[N];
        vis = new boolean[N];
        for (int i = 0; i != N; i++) adj[i] = new HashSet < > ();
        for (int i = 0; i != N; i++)
            for (int j = i + 1; j != N; j++)
                if (similar(A[i], A[j])) { //add an edge between these two nodes
                    // System.out.println(A[i]+", "+A[j]);
                    adj[i].add(j);
                    adj[j].add(i);
                }
        for (int i = 0; i != N; i++) {
            if (vis[i]) continue; //res tracks only the starts of groups
            res++;
            dfs(i);
        }
        return res;
    }

    void dfs(int curr) {
        if (vis[curr]) return; //mark all of the nodes in this group as visited
        vis[curr] = true;
        for (int nei: adj[curr]) dfs(nei);
    }

    boolean similarSLOW(String S, String T) {
        char s = '.', t = '.';
        int N = S.length();
        char[] sarr = S.toCharArray(), tarr = T.toCharArray();
        for (int i = 0; i != N; i++)
            if (sarr[i] != tarr[i])
                if (s == '.') {
                    s = sarr[i];
                    t = tarr[i]; //first inconsistency found
                } else if (sarr[i] == t && tarr[i] == s) s = '*'; //perfect swap found
        else return false; //inconsistency, but not first or the perfect second

        return true;
    }
    
    boolean similar(String s, String t) {   //a little faster (Runtime: 478 ms, faster than 28.28% of Java online submissions.)
        int res = 0, i = 0;
        while(res <= 2 && i < s.length()){
            if(s.charAt(i) != t.charAt(i)) res++;
            i++;
        }
        return res == 2 || res==0;
    }
}
