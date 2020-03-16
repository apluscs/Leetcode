class Solution {
public:
    const int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    vector<vector<int>> allCellsDistOrder(int N, int M, int r0, int c0) {
        queue<pair<int,int>> que;
        vector<vector<int>> res;
        que.push(make_pair(r0, c0));
        unordered_set<int> vis;
        while(!que.empty()){    // just normal bfs
            auto p = que.front();   que.pop();
            int id = p.first * M + p.second;
            if(p.first == -1 || p.second == -1 || p.first == N || p.second == M || vis.count(id)) continue;
            res.push_back({p.first, p.second});
            vis.insert(id);
            for(const int* d: dir)
                que.push(make_pair(p.first + d[0], p.second + d[1]));
        }
        return res;
    }
};
