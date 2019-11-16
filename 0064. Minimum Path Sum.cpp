class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        const int N=grid.size(), M=grid[0].size();
        for(int j=1;j!=M;j++) grid[0][j]+= grid[0][j-1];
        for(int i=1;i!=N;i++) grid[i][0]+= grid[i-1][0];
        for(int i=1;i!=N;i++)
            for(int j=1;j!=M;j++)
                grid[i][j]+=min(grid[i-1][j],grid[i][j-1]);
        
        return grid[N-1][M-1];
    }
};
