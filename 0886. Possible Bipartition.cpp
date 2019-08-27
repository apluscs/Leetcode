class Solution {
    public:
        bool flag;
        bool possibleBipartition(int N, vector < vector < int >> & dislikes) {
            flag = false;
            vector < int > camps(N + 1);
            vector < unordered_set < int >> adj(N + 1); //no 0
            for (vector < int > dis: dislikes) {
                adj[dis[0]].insert(dis[1]);
                adj[dis[1]].insert(dis[0]);
            }
            for (int i = 1; i != N + 1; i++) {
                if (camps[i] != 0) continue; //already been placed, don't want the arbitraily assigned 1 to mess with it
                dfs(i, 1, camps, adj);
                if (flag) return false;
            }
            return true;
        }

        void dfs(int curr, int cmp, vector < int > & camps, vector < unordered_set < int >> & adj) {
            if (flag || camps[curr] == cmp) return;
            if (camps[curr] == 3 - cmp) {
                flag = true;
                return; //mismatch found, system fails
            }
            camps[curr] = cmp;
            for (int nei: adj[curr]) dfs(nei, 3 - cmp, camps, adj); //assign disliked people to opposite camp 
        }
};
