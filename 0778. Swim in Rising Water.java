class Solution {
    int[][] grid;
    int N;
    int[][] dir = new int[][] { {-1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 } };

    public int swimInWater(int[][] gd) {
        grid = gd;
        N = grid.length;
        int low = grid[0][0], high = N * N - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (able(mid, 0, 0, new boolean[N][N])) high = mid - 1;
            else low = mid + 1;
        }
        return low; //high is the first we cannot do
    }

    boolean able(int max, int i, int j, boolean[][] vis) {
        if (i == -1 || i == N || j == -1 || j == N || grid[i][j] > max || vis[i][j]) return false;
        if (i == N - 1 && j == N - 1) return true; //must come after ^ in case grid[i][j]>max
        vis[i][j] = true;
        for (int[] d: dir) {
            if (able(max, i + d[0], j + d[1], vis)) return true;
        }
        return false;
    }
}
