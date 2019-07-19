class Solution {
    int N,currSize,currClass;   //N is height, M is width
    int[][] grid;
    int[] size;
    final int[][] dir={{0,1},{0,-1},{1,0},{-1,0}};
    public int largestIsland(int[][] g) {
        grid=g; size=new int[625];
        N=grid.length;  currClass=2;    int res=1;  //if all of grid is 0, you can make at least one 1
        for(int i=0;i!=N;i++){
            for(int j=0;j!=N;j++){
                if(grid[i][j]==1){
                    currSize=0;
                    helper(i,j);
                    size[currClass]=currSize;
                    // res=Math.max()
                    currClass++;
                }
            }
        }
        for(int[] gr:grid) System.out.println(Arrays.toString(gr));
        System.out.println(Arrays.toString(size));
        for(int i=0;i!=N;i++){
            for(int j=0;j!=N;j++){
                if(grid[i][j]==0){
                    if(i!=0&&i!=N-1&&grid[i-1][j]!=grid[i+1][j]){
                        res=Math.max(res,size[grid[i-1][j]]+size[grid[i+1][j]]+1);
                    }
                    if(j!=0&&j!=N-1&&grid[i][j-1]!=grid[i][j+1]){
                        res=Math.max(res,size[grid[i][j-1]]+size[grid[i][j+1]]+1);
                    }
                }
            }
        }
        return res;
    }
    
    void helper(int r, int c){
        if(r==-1||r==N||c==-1||c==N||grid[r][c]!=1) return;
        currSize++;
        grid[r][c]=currClass;
        for(int[] d:dir){
            helper(r+d[0],c+d[1]);
        }
    }
    int addIsland(int r1,int c1,int r2,int c2){
        if(out(r1)||out(c1)||out(r2)||out(c2)) return 0;
        return size[grid[r1][c1]]+size[grid[r2][c2]];
    }
    boolean out(int p){
        return p==0||p==N;
    }
}
