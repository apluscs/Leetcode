class Solution {  //TIME LIMIT EXCEEDED
    final int MOD = 1000000007;
    public int uniqueLetterString(String S) {
        int N = S.length();
        long res = 0;
        for (int i = 0; i != N; i++) { //start is defined by i
            int ct = 0;
            int[] vis = new int[26];
            Arrays.fill(vis, 1);
            for (int j = i; j != N; j++) {
                int c = S.charAt(j) - 'A';
                ct += vis[c]; //1 if new, -1 if we've seen once (to remove the one we added), 0 if we've seen twice
                if (vis[c] == 1) vis[c] = -1;
                else if (vis[c] == -1) vis[c] = 0;
                // System.out.print(ct+", ");
                res = (res + ct) % MOD;
            }
            // System.out.println();
        }
        return (int) res;
    }
}
