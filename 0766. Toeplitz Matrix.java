class Solution {
    public boolean isToeplitzMatrix(int[][] grid) {
        HashMap < Integer, Integer > map = new HashMap < > ();
        for (int i = grid.length - 1; i != -1; i--)
            for (int j = grid[0].length - 1; j != -1; j--) {
                if (!map.containsKey(i - j)) map.put(i - j, grid[i][j]); //every element on the same diagonal has the same (i-j) value
                if (map.get(i - j) != grid[i][j]) return false;
            }
        return true;
    }
    //Runtime: 3 ms, faster than 29.88% of Java online submissions for Toeplitz Matrix.
    //Memory Usage: 39.8 MB, less than 99.90% of Java online submissions for Toeplitz Matrix.
}

class SolutionOther {
    public boolean isToeplitzMatrix(int[][] grid) {
        for (int i = grid.length - 1; i != 0; i--)	//notice bounds ensure no IndexOutOfBounds Exception
            for (int j = grid[0].length - 1; j != 0; j--)
                if (grid[i][j] != grid[i - 1][j - 1]) return false;
        return true;
    }
}
//Runtime: 1 ms, faster than 100.00% of Java online submissions for Toeplitz Matrix.
//Memory Usage: 44.3 MB, less than 76.31% of Java online submissions for Toeplitz Matrix.
