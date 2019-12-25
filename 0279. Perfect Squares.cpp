class Solution {
    public:
        int numSquares(int N) {
            if (N <= 0) return 0;
            static vector < int > dp({ 0 });  //values in here remain the same every time, so don't waste time recomputing stuff 
            dp[0] = 0;  
            while (dp.size() <= N) {  //only compute dp at values you don't know the answer to
                int i = dp.size(), res = INT_MAX;
                for (int j = 1; j * j <= i; j++)
                    res = min(res, dp[i - j * j] + 1);
                dp.push_back(res);
            }
            return dp[N];
        }
};

class Solution2 {
    public:
        int numSquares(int N) {
            if (N <= 0) return 0;
            vector < int > dp(N + 1, INT_MAX);
            dp[0] = 0;
            for (int i = 1; i != N + 1; i++)
                for (int j = 1; j * j <= i; j++) //try subtracting all perf squares <= i
                    dp[i] = min(dp[i], dp[i - j * j] + 1); // option: #ways without j*j, then add j*j (+1 square)
            return dp[N];
        }
};

class SolutionBFS {
    public:
        int numSquares(int N) {
            unordered_set < int > vis;
            queue < int > que;
            int res = 0; // level of breadth from center of graph
            que.push(0);
            while (!que.empty()) {
                int M = que.size();
                for (int i = 0; i != M; i++) {
                    int curr = que.front();
                    que.pop();
                    if (curr == N) return res;
                    if (vis.count(curr)) continue;
                    vis.insert(curr); // mark as visited
                    for (int j = 1; j * j + curr <= N; j++)
                        que.push(j * j + curr); // add all valid squares to curr
                }
                res++; // this level all checked out, try next one
            }
            return res;
        }
};
