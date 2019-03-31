class Solution {
    public String longestPalindrome(String s) {
        int N=s.length();
        if(N==0) return "";
        boolean[][] dp=new boolean[N][N];
        String res=s.charAt(0)+"";
        int max=1;
        for(int i=0;i<N;i++) dp[i][i]=true;
        for(int i=0;i<N-1;i++) 
            if(s.charAt(i)==s.charAt(i+1)) {    //all pals of length 2
                dp[i][i+1]=true;
                max=2;
                res=s.substring(i,i+2);
            }    
        for(int i=N-3;i>=0;i--){    //last two rows are completely filled
            for(int j=N-1;j!=i+1;j--){
                if(dp[i+1][j-1]&&s.charAt(i)==s.charAt(j)){ //everything in between are palindromes
                    dp[i][j]=true;
                    if(j-i+1>max){
                        max=j-i+1;
                        res=s.substring(i,j+1);
                    }
                }
            }
        }
        return res;
    }
}
