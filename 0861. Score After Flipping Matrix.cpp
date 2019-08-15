class Solution {
    public:
        int matrixScore(vector < vector < int >> & A) {
            int N = A.size(), M = A[0].size(), res = 0;
            res += N * (1 << (M - 1)); //toggle all left column elems to 1 because those are MVPs
            for (int j = 1; j != M; j++) {
                int exst = 0; //# 1's in this column
                for (int i = 0; i != N; i++) exst += A[i][j] == A[i][0]; //if same, exst++; otherwise stays constant 
                //[used for when we toggled this row to get leftmost elem to be 1, need to ensure that all elems are toggled]
                res += max(exst, N - exst) * (1 << (M - 1 - j)); //either toggle this column or don't; do whichever gives you more 1's
                // cout<<res<<endl;
            }
            return res;
        }
};
