class Solution {
    public:
        int lenLongestFibSubseq(vector < int > & A) {
            int N = A.size(), res = 0;
            unordered_map < int, int > index(N);
            vector < vector < int >> dp(N, vector < int > (N));
            for (int i = 0; i != N; i++) index[A[i]] = i;
            for (int k = 0; k != N; k++)
                for (int j = 0; j != N; j++) {
                    int df = A[k] - A[j]; //num that should come before A[j] in fib subseq
                    if (df < A[j] && index.count(df)) {
                        int i = index[df];
                        dp[j][k] = dp[i][j] + 1; //dp[j][k]=length of longest fib subseq ending in A[j],A[k]
                        res = max(res, dp[j][k] + 2); //for starting 2 nums
                    }
                }
            // for(vector<int> d:dp){
            //     for(int n:d) cout<<n<<", ";
            //     cout<<endl;
            // }

            return res > 2 ? res : 0;
        }
};
