class Solution {
    final int MOD = 1000000007;
    public int numFactoredBinaryTrees(int[] A) {
        int N = A.length;
        Arrays.sort(A);
        long[] dp = new long[N];
        Arrays.fill(dp, 1); //each can be a tree by itself
        HashMap < Integer, Integer > map = new HashMap < > ();
        for (int i = 0; i != N; i++) {
            map.put(A[i], i); //maps value to index
            for (int j = 0; j != i; j++) { //no A[i]=1, so n=n*1 can't be a binary tree
                if (A[i] % A[j] == 0 && map.containsKey(A[i] / A[j])) //factor pair found
                    dp[i] = (dp[i] + dp[j] * dp[map.get(A[i] / A[j])]) % MOD; 
                    //add #ways to make factor1 * #ways to make factor2 to dp[i], then mod it
            }
        }
        long res = 0;
        for (long d: dp) res += d; //<=1000 ints, so can't go over long's max
        return (int)(res % MOD);
    }
}
