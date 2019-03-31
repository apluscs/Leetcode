class Solution {
    public int maximalRectangle(char[][] matrix) {
        if(matrix.length==0)return 0;
        int N=matrix.length;    int M=matrix[0].length;
        int[][] hgt=new int[N+1][M+1];  //extra row and column 
        int[][] left=new int[N+1][M+1];
        int[][] right=new int[N+1][M+1];
        for(int j=0;j<M;j++) for(int i=0;i<N;i++)
            if(matrix[i][j]=='1') hgt[i+1][j+1]=hgt[i][j+1]+1;
        // for(int i=1;i<=N;i++)System.out.println(Arrays.toString(hgt[i]));
        for(int i=0;i<N;i++) {
            int curr=0; //leftmost '1' of current rectangle
            for(int j=0;j<M;j++){   //to ensure continuity vertically, takes less optimal left from above if needed
                if(matrix[i][j]=='1') left[i+1][j+1]=Math.max(curr,left[i][j+1]);
                else curr=j+1;  //update bound
            }
            // System.out.println(Arrays.toString(left[i+1]));
        }
        System.out.println();
        Arrays.fill(right[0],M);
        for(int i=0;i<N;i++){
            int curr=M; //index of '0' immediately following right bound of rectangle
            for(int j=M-1;j!=-1;j--){   //again, to ensure continuity (case where row above doesn't extend as far right as you do)
                if(matrix[i][j]=='1') right[i+1][j+1]=Math.min(right[i][j+1],curr);
                else{
                    curr=j;
                    right[i+1][j+1]=M;
                }
            }
            // System.out.println(Arrays.toString(right[i+1]));
        }
        int res=0;
        for(int i=1;i<=N;i++) for(int j=1;j<=M;j++){
            res=Math.max(res,hgt[i][j]*(right[i][j]-left[i][j]));
            // System.out.println(res);
        }
        return res;            
    }
}
