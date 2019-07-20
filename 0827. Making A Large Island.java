class Solution {
    int N, currSize, currClass; //N is height
    int[][] grid;
    int[] size;
    final int[][] dir = { { 0, 1 }, { 0, -1 }, { 1, 0 }, {-1, 0 } };

    public int largestIsland(int[][] g) {
        grid = g;
        size = new int[625];
        N = grid.length;
        currClass = 2;
        int res = 1; //if all of grid is 0, you can make at least one 1
        for (int i = 0; i != N; i++)
            for (int j = 0; j != N; j++)
                if (grid[i][j] == 1) {
                    currSize = 0; //size of current island examined
                    helper(i, j);
                    size[currClass] = currSize;
                    res = Math.max(res, currSize);
                    currClass++; //each island group has its own number
                }
        // for(int[] gr:grid) System.out.println(Arrays.toString(gr));
        // System.out.println(Arrays.toString(size));
        for (int i = 0; i != N; i++)
            for (int j = 0; j != N; j++)
                if (grid[i][j] == 0)
                    res = Math.max(addIsland(i, j) + 1, res);
        return res;
    }

    void helper(int r, int c) { //dfs
        if (out(r) || out(c) || grid[r][c] != 1) return;
        currSize++;
        grid[r][c] = currClass;
        for (int[] d: dir) //expand to all 4 cardinal directions to reach bounds of current island
            helper(r + d[0], c + d[1]);
    }
    
    int addIsland(int i, int j) {
        HashSet < Integer > vis = new HashSet < > (); //so that we don't double count the same island
        int res = 0;
        for (int[] d: dir) { //combined island size = combination of islands directly NESW of it
            int ni = i + d[0], nj = j + d[1]; //new coordinates
            if (!out(ni) && !out(nj) && !vis.contains(grid[ni][nj])) {
                vis.add(grid[ni][nj]);
                res += size[grid[ni][nj]];
            }
        }
        return res;
    }
    
    boolean out(int p) {    //checks if index is out of bounds
        return p == -1 || p == N;
    }
}
