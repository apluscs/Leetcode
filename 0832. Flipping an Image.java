class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        int N = A.length;
        for (int i = 0; i != N; i++)
            for (int j = 0; j <= (N - 1) / 2; j++) { //odd N = reaches middle, even numbers =  doesn't pass middle
                int left = A[i][j]; //swap algorithm
                A[i][j] = 1 - A[i][N - j - 1];
                A[i][N - j - 1] = 1 - left; //for middle column, third statement overwrites second --> value is 1-original (left)
            }
        return A;
    }
}
