class Solution {
public:
    const int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int N = matrix.size();
        if(N == 0) return res;
        int M = matrix[0].size();
        if(M == 0) return res;
        res.reserve(N * M);

        unordered_set<int> vis; // mark what you saw as visited
        int i = 0, j = 0, d = 0;
        while(vis.count(i * M + j) == 0 && i != -1 && j != -1 && i != N && j != M){  // only happens when we're finally done
            // cout << i << ", " << j << endl;
            res.push_back(matrix[i][j] );
            vis.insert(i * M + j);
            int ni = i + dir[d][1], nj = j + dir[d][0];
            if(ni == -1 || nj == -1 || ni == N || nj == M || vis.count(ni * M + nj))
                d = (d+1) % 4;  // turn 90 to the right
            i += dir[d][1];
            j += dir[d][0];
            
        }

        return res;
    }
};
