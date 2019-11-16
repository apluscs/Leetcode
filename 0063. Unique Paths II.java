/*
class Solution {  //being a beech with int overflow, much easier to use Java
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int N=grid.size(), M=grid[0].size();
        if(grid[0][0]) return 0;
        grid[0][0]=1;   //1 way to get to first cell
        for(int i=1;i!=M;i++){
            grid[0][i]= grid[0][i] ? 0:grid[0][i-1];
        }

        for(int i=1;i!=N;i++){
            grid[i][0]= grid[i][0] ? 0:grid[i-1][0];
            for(int j=1;j!=M;j++){
                grid[i][j] = grid[i][j] ? 0: grid[i-1][j]+grid[i][j-1];
                cout<<grid[i][j]<<" ";
            }cout<<endl;
        }
        return grid[N-1][M-1];
    }
};
*/

class Solution {
    public int uniquePathsWithObstacles(int[][] grid) {
        int N=grid.length, M=grid[0].length;
        if(grid[0][0]==1) return 0;
        grid[0][0]=1;   //1 way to get to first cell
        for(int i=1;i!=M;i++){
            grid[0][i]= grid[0][i]==1 ? 0:grid[0][i-1];
        }

        for(int i=1;i!=N;i++){
            grid[i][0]= grid[i][0]==1 ? 0:grid[i-1][0];
            for(int j=1;j!=M;j++){
                grid[i][j] = grid[i][j]==1 ? 0: grid[i-1][j]+grid[i][j-1];
                // cout<<grid[i][j]<<" ";
            }
            // cout<<endl;
        }
        return grid[N-1][M-1];
    }
}
