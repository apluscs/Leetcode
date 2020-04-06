class Solution {
public:
    const int dir[9][2] = {{0,0}, {1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
    
    vector<int> gridIllumination(int N, vector<vector<int>>& lamps, vector<vector<int>>& queries) {
        vector<int> res;
        res.reserve(queries.size());
        unordered_map<int, int> rows, cols, up_diag, down_diag; // tracks #lamps in each row, col, ascending diag, and descending diag
        
        unordered_set<long> on;
        for(auto lamp : lamps){
            int i = lamp[0], j = lamp[1];
            on.insert(long(i) * N + j);
            rows[i]++;  cols[j]++;  up_diag[i+j]++; down_diag[j-i + N - 1]++;
        }

        for(auto que : queries){
            int i = que[0], j = que[1];   long id = long(i) * N + j;
            bool lit = rows[i] || cols[j] || up_diag[i+j] || down_diag[j-i + N - 1];
            res.push_back(lit ? 1 : 0);
            if(!lit) continue;
            for(auto d : dir){
                int ni = i + d[0], nj = j + d[1];   long nid = long(ni) * N + nj;
                if(ni == -1 || nj == -1 || ni == N || nj == N || on.count(nid) == 0) continue;  // out of bounds or unlit
                rows[ni]--;  cols[nj]--;  up_diag[ni + nj]--; down_diag[nj - ni + N - 1]--;
                on.erase(nid);
            }
        }
        
        return res;
    }
};
