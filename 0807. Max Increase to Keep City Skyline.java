class Solution {
    public int maxIncreaseKeepingSkyline(int[][] grid) {
        int N = grid.length;
        int[] vert = new int[N];
        int[] horz = new int[N]; //skyline from north is same as the one from south view, same with east and west
        for (int i = 0; i != N; i++)
            for (int j = 0; j != N; j++) {
                vert[i] = Math.max(vert[i], grid[i][j]); //skyline is shaped by tallent building in that row/column
                horz[j] = Math.max(horz[j], grid[i][j]);
            }
        // System.out.println(Arrays.toString(vert));  System.out.println(Arrays.toString(horz));
        int res = 0;
        for (int i = 0; i != N; i++)
            for (int j = 0; j != N; j++)
                res += Math.min(vert[j], horz[i]) - grid[i][j]; //add until you break the skyline from horizontal/vertical viewpoint
        return res;
    }
}
