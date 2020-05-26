class Solution {
public:
    const int dir[4][2] = {{1,0}, {0,1}, {-1,0}, {0,-1}};
    vector<vector<int>>  generateMatrix(int N) {
        vector<vector<int>> res(N, vector<int>(N));
        if(N == 1){ // saves some bounds checking hassle
            res[0][0] = 1;
            return res;
        }
        int num = 1, i = 0, j = 0, d = 0;
        while(res[i][j] == 0){  // only happens when we're finally done
            res[i][j] = num++;
            int ni = i + dir[d][1], nj = j + dir[d][0];
            if(ni == -1 || nj == -1 || ni == N || nj == N || res[ni][nj] != 0)
                d = (d+1) % 4;  // turn 90 to the right
            i += dir[d][1];
            j += dir[d][0];
        }

        return res;
    }
};
