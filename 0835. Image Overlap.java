class Solution {
    public int largestOverlap(int[][] A, int[][] B) {
        int N = A.length, res = 0; //running 2 concurrent ops: moving B's bot right corner from A[0][0] to [N-1][N-1], 
        //also moving B's top left corner from A[N-1][N-1] to [0][0]
        for (int di = 0; di != N; di++) //di is offset from start position (down for op1 or up for op2)
            for (int dj = 0; dj != N; dj++) { //dj is offset horizontally (left or right)
                int count1 = 0, count2 = 0; //count #overlapping ones
                for (int i = 0; i <= di; i++)
                    for (int j = 0; j <= dj; j++) {
                        if (A[i][j] == 1 && B[i + N - 1 - di][j + N - 1 - dj] == 1) count1++; //B's coordinates are >= to A's
                        if (B[i][j] == 1 && A[i + N - 1 - di][j + N - 1 - dj] == 1) count2++; //other way around: A and B swap positions
                    }
                // System.out.println(count1+"*******"+count2);
                res = Math.max(res, Math.max(count1, count2));
            }
        return res;
    }
}
