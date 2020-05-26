class Solution {
public:
    int countServers(vector<vector<int>>& grid) {  
        unordered_set<int> res;
        int N = grid.size(), M = grid[0].size();
        for(int i = 0; i != N; ++i){
            int count = 0;
            for(int j = 0; j != M; ++j) count += grid[i][j];
            if(count < 2) continue;
            for(int j = 0; j != M; ++j)
                if(grid[i][j] == 1)
                    res.insert(i * M + j);
        }
        for(int j = 0; j != M; ++j){
            int count = 0;
            for(int i = 0; i != N; ++i) count += grid[i][j];
            if(count < 2) continue;
            for(int i = 0; i != N; ++i)
                if(grid[i][j] == 1)
                    res.insert(i * M + j);
        }
        
        return res.size();
    }
};
