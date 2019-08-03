class Solution {
    public int numMagicSquaresInside(int[][] grid) {
        int N = grid.length, M = grid[0].length, res = 0;
        for (int i = 0; i < N - 2; i++)
            for (int j = 0; j < M - 2; j++)
                if (isMagic(i, j, grid))
                    res++;
        // System.out.println(i+", "+j);
        return res;
    }

    boolean isMagic(int I, int J, int[][] grid) { //I and J are top left coordinates
        boolean[] vis = new boolean[10]; //track which numbers you've seen in this subgrid 
        for (int i = I; i != I + 3; i++)
            for (int j = J; j != J + 3; j++) {
                if (grid[i][j] == 0 || grid[i][j] > 9 || vis[grid[i][j]]) return false; //must be 1-9
                vis[grid[i][j]] = true;
            }

        int r1 = grid[I][J] + grid[I][J + 1] + grid[I][J + 2];
        int next = grid[I + 1][J] + grid[I + 1][J + 1] + grid[I + 1][J + 2];
        if (next != r1) return false; //row 2
        // System.out.println("***");
        next = grid[I + 2][J] + grid[I + 2][J + 1] + grid[I + 2][J + 2];
        if (next != r1) return false; //row 3
        // System.out.println("***");

        next = grid[I][J] + grid[I + 1][J] + grid[I + 2][J];
        if (next != r1) return false;
        // System.out.println("***");
        next = grid[I][J + 1] + grid[I + 1][J + 1] + grid[I + 2][J + 1]; //column 2
        if (next != r1) return false;
        // System.out.println("***");
        next = grid[I][J + 2] + grid[I + 1][J + 2] + grid[I + 2][J + 2]; //column 3
        if (next != r1) return false;
        // System.out.println("***");

        next = grid[I][J] + grid[I + 1][J + 1] + grid[I + 2][J + 2]; //main diag
        if (next != r1) return false;
        // System.out.println("***");
        next = grid[I][J + 2] + grid[I + 1][J + 1] + grid[I + 2][J]; //other diag
        if (next != r1) return false;
        // System.out.println("***");

        return true;
    }
}
