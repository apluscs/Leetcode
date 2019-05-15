class SolutionBFS {
    public int[][] floodFill(int[][] grid, int sr, int sc, int newColor) {
        if (newColor == grid[sr][sc]) return grid;  //no need to make any changes
        Queue < Integer > que = new LinkedList < > ();
        int og = grid[sr][sc]; //original color we need to look for
        que.add(sr * 100 + sc); //code for the location of each cell
        while (!que.isEmpty()) {
            int r = que.poll();
            int c = r % 100;
            r /= 100;
            grid[r][c] = newColor;
            if (r != 0 && grid[r - 1][c] == og) { //check bounds and make sure it's the right color and unvisited
                que.add((r - 1) * 100 + c);
            }
            if (r != grid.length - 1 && grid[r + 1][c] == og) {
                que.add((r + 1) * 100 + c);
            }
            if (c != 0 && grid[r][c - 1] == og) {
                que.add(r * 100 + c - 1);
            }
            if (c != grid[0].length - 1 && grid[r][c + 1] == og) {
                que.add(r * 100 + c + 1);
            }
        }
        return grid;
    }
}

class SolutionDFS { //actually performs worse than BFS, even in memory usage
    int[][] grid;
    public int[][] floodFill(int[][] image, int sr, int sc, int newColor) {
        grid = image;
        if (newColor != grid[sr][sc])
            helper(sr, sc, grid[sr][sc], newColor);
        return grid;
    }
    public void helper(int r, int c, int og, int newCol) {
        grid[r][c] = newCol;
        if (r != 0 && grid[r - 1][c] == og) helper(r - 1, c, og, newCol);
        if (r != grid.length - 1 && grid[r + 1][c] == og) helper(r + 1, c, og, newCol);
        if (c != 0 && grid[r][c - 1] == og) helper(r, c - 1, og, newCol);
        if (c != grid[0].length - 1 && grid[r][c + 1] == og) helper(r, c + 1, og, newCol);
    }
}
