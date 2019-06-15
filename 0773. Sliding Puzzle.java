class Solution {
    public int slidingPuzzle(int[][] board) {
        Queue < State > que = new LinkedList < > ();
        HashSet < Integer > vis = new HashSet < > ();
        que.add(new State(board, 0));
        while (!que.isEmpty()) {
            State s = que.poll();
            int[][] curr = s.board;
            // print(curr);
            // System.out.println(encode(curr));
            // System.out.println();
            int code = encode(curr);
            if (vis.contains(code)) continue;
            vis.add(code);
            if (curr[0][0] == 1 && curr[0][1] == 2 && curr[0][2] == 3 && curr[1][0] == 4 && curr[1][1] == 5) return s.lev;
            int i = -1, j = -1; //locate position of the zero (free space)
            for (int r = 0; r != 2; r++)
                for (int c = 0; c != 3; c++)
                    if (curr[r][c] == 0) {
                        i = r;
                        j = c;
                        break;
                    }
            if (i == 1) { //can either slide up or down
                int[][] next = swap(curr, i, j, i - 1, j);
                // que.add(new State(curr.clone(),s.lev+1));    does not work because cloning a 2d array points rows to the rows of the original, so original is still modified when the clone is modified
                que.add(new State(next, s.lev + 1));
                swap(curr, i, j, i - 1, j);
            } else {
                int[][] next = swap(curr, i, j, i + 1, j);
                que.add(new State(next, s.lev + 1));
                swap(curr, i, j, i + 1, j);
            }
            if (j != 0) { //may be able to slide left and right if it's in the middle
                int[][] next = swap(curr, i, j, i, j - 1);
                que.add(new State(next, s.lev + 1));
                swap(curr, i, j, i, j - 1);
            }
            if (j != 2) {
                int[][] next = swap(curr, i, j, i, j + 1);
                que.add(new State(next, s.lev + 1));
                swap(curr, i, j, i, j + 1);
            }
        }
        return -1;
    }

    public static int[][] swap(int[][] nums, int i, int j, int ni, int nj) {
        int[][] res = new int[2][3];
        res[0] = nums[0].clone();
        res[1] = nums[1].clone();
        res[i][j] = nums[ni][nj];
        res[ni][nj] = nums[i][j];
        return res;
    }

    public static int encode(int[][] nums) {
        int res = 0;
        for (int[] n: nums)
            for (int num: n) res = res * 10 + num;
        return res;
    }

    public class State {
        int[][] board;
        int lev;
        public State(int[][] board, int lev) {
            this.board = board;
            this.lev = lev;
        }
    }

    public static void print(int[][] nums) {
        for (int[] n: nums) System.out.println(Arrays.toString(n));
        System.out.println();
    }
}

/*A little disappointed :/
Runtime: 9 ms, faster than 41.23% of Java online submissions for Sliding Puzzle.
Memory Usage: 36.4 MB, less than 99.80% of Java online submissions for Sliding Puzzle.*/
