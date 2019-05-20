class Solution {  //wrong answer, just a draft
    public int cherryPickup(int[][] grid) {
        int N=grid.length;
        int[][] p1=dp(grid);
        if(p1[N-1][N-1]==0) return 0;
        backtrack(grid,p1); //if no path, we won't backtrack
        for(int[] a:grid) System.out.println(Arrays.toString(a));
        System.out.println();
        int[][] p2=dp(grid);
        if(p2[N-1][N-1]==0) return 0;
        return p1[N-1][N-1]+p2[N-1][N-1];
    }
    public int[][] dp(int[][] grid){
        int N=grid.length;
        int[][] dp=new int[N][N];
        for(int i=0;i!=N;i++){
            for(int j=0;j!=N;j++){
                if(grid[i][j]==-1){
                    dp[i][j]=0; continue;
                }
                if(i!=0&&j!=0) dp[i][j]=Math.max(dp[i-1][j],dp[i][j-1])+grid[i][j];
                else if(j!=0) dp[i][j]=dp[i][j-1]+grid[i][j];
                else if(i!=0) dp[i][j]=dp[i-1][j]+grid[i][j];
            }
        }
        // for(int[] a:dp) System.out.println(Arrays.toString(a));
        return dp;
    }
    public void backtrack(int[][] grid,int[][] dp){
        int[] loc=new int[] {grid.length-1,grid.length-1};
        while(loc[0]!=0||loc[1]!=0){
            int i=loc[0],j=loc[1];
            int curr=dp[i][j];
             System.out.println("i: "+i+", j: "+j+", curr: "+curr);
            if(i!=0&&grid[i-1][j]!=-1&&(dp[i-1][j]==curr||dp[i-1][j]==curr-1)){
                loc[0]=i-1;
            } else loc[1]=j-1;
            grid[i][j]=0;
        }
    }
}
