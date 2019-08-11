class Solution {
    public:
        vector < int > loudAndRich(vector < vector < int >> & richer, vector < int > & quiet) {
            int N = quiet.size();
            vector < int > res(N, -1);
            vector < vector < int >> adj(N); //2D array, one spot for each index in quiet
            for (vector < int > edge: richer) adj[edge[1]].push_back(edge[0]); //arrows always point to nodes richer than you
            // for(vector<int> a:adj){
            //     for(int b:a) cout<<b<<", ";
            //     cout<<endl;
            // }
            for (int i = 0; i != N; i++) dfs(i, adj, quiet, res); //process this entire tree at once, saves time
            return res;

        }

    int dfs(int curr, vector < vector < int >> & adj, vector < int > & quiet, vector < int > & res) {
        if (res[curr] != -1) return res[curr];
        res[curr] = curr; //gotta start from somewhere, at least you are as rich as yourself
        for (int nei: adj[curr]) {
            res[nei] = dfs(nei, adj, quiet, res);
            if (quiet[res[nei]] < quiet[res[curr]]) res[curr] = res[nei];
        }
        return res[curr];
    }
};
