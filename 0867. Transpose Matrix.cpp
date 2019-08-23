class Solution {
    public:
        vector < vector < int >> transpose(vector < vector < int >> & A) {
            int N = A.size(), M = A[0].size();
            vector < vector < int >> res(M);
            for (int j = 0; j != M; j++) { //for each column in A
                res[j].resize(N); //create a new row
                for (int i = 0; i != N; i++)
                    res[j][i] = A[i][j]; //switch coordinates
            }
            return res;
        }
};
