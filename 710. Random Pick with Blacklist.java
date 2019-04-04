class Solution {
    public static int M;
    public static Map < Integer, Integer > map;
    public Solution(int N, int[] blacklist) {
        M = N - blacklist.length; //N--;
        map = new HashMap < > ();
        for (int n: blacklist) map.put(n, -1); //now it stores all bad nums
        for (int n: blacklist) {
            if (n >= M) continue; //everything below M is pool of valid nums
            while (map.containsKey(--N)) {}
            map.put(n, N); //need to find the first valid num above M, match n to that
        }
    }

    public int pick() {
        int r = (int)(Math.random() * M); //max = M-1
        return map.containsKey(r) ? map.get(r) : r; //if map contains it, it means it was bad and was mapped to something good; otherwise, it was good to begin with
    }
}

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(N, blacklist);
 * int param_1 = obj.pick();
 */
