class Solution {
    public String pushDominoes(String dominoes) {
        int N=dominoes.length(); int[] forces=new int[N]; char[] str=dominoes.toCharArray();
        if(str[0]=='R') forces[0]=N;    //any other case = 0
        
        for(int i=1;i!=N;i++){
            if(str[i]=='R') forces[i]=N;
            // else if(str[i]=='L') forces[i]=0;
            else if(str[i]=='.') forces[i]=Math.max(0,forces[i-1]-1);
        }
        // System.out.println(Arrays.toString(forces));

        int prev=0; //the value you subtracted from the one immediately right of you
        for(int i=N-1;i!=-1;i--){
            if(str[i]=='L') prev=N;
            else if(str[i]=='.') prev=Math.max(0,prev-1);
            else prev=0;    //we got an 'R'
            forces[i]-=prev;
        }
        // System.out.println(Arrays.toString(forces));
        StringBuilder res= new StringBuilder();
        for(int val:forces){
            if(val>0) res.append('R');
            else if(val<0) res.append('L');
            else res.append('.');
        }
        return res.toString();
    }
}
