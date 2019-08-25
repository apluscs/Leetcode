class Solution {
    public:
        bool stoneGame(vector < int > & A) {
            int N = A.size(), dp[N][N] = { 0 };
            for (int i = 0; i != N; i++) dp[i][i] = A[i];
            for (int i = 0; i != N; i++)
                for (int j = i + 1; j != N; j++) //dp[i][j]=max profit you can get if you go first using the boardtiles from i to j inclusive
                    dp[i][j] = max(A[i] - dp[i + 1][j], A[j] - dp[i][j - 1]); //take right stone & subtract B's profit from leftside 
                    //OR take left stone & subtract B's profit from rightside

            // for(int i=0;i!=N;i++){
            //      for(int j=i;j!=N;j++)
            //          cout<<dp[i][j]<<", ";
            //      cout<<endl;
            // }  
            return dp[0][N - 1] > 0;
        }
};
