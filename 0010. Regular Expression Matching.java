class Solution {
    public static boolean[][] ext,memo; //ext tracks if memo[i][j] is legit or just the default "false"
    public static int N,M;
    public static String s, p;
    public boolean isMatch(String str, String pat) {
        N=str.length();   M=pat.length();   ext=new boolean[N+1][M+1];  memo=new boolean[N+1][M+1];
        s=str;   p=pat;
        boolean res= helper(0,0);
        return res;
    }
    public boolean helper(int i,int j){
        // System.out.println(i+", "+j);
        if(i>N||j>M) return false;  //avoid out of bounds errors
        if(ext[i][j]) return memo[i][j];    //when do we ever use this?
        boolean res;
        if(j==M) res = i==N;    //if i is less, it means we exhausted pattern without filling str
        else{
            boolean match = i<N && s.charAt(i)==p.charAt(j) || p.charAt(j)=='.';
            if(j<M-1 && p.charAt(j+1)=='*') //opt 1: skip over this char by repeating 0 times
                res=helper(i,j+2) || match && helper(i+1,j);    //or see if * can substitute for later chars
            else  res=match&&helper(i+1,j+1);   //standard, just check if next chars match
        }
        memo[i][j]=res;
        ext[i][j]=true;
        return res;
    }
}
