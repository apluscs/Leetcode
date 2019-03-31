class Solution {
    public String convert(String s, int k) {
        int N=s.length();
        if(k==1) return s;
        StringBuilder res=new StringBuilder(N);
        for(int i=0;i<N;i+= 2*(k-1)){   // top row, jump by 2(k-1) each time
            res.append(s.charAt(i));    
            // System.out.println(i);
        }
        for(int st=1;st<k-1;st++){  //middle rows
            int col=0, i=st;  
            while(i<N){
                res.append(s.charAt(i));
                if(col%2==0) i+= 2*(k-st-1);    //jump dist changes depending on col
                else i+= 2*st;
                col++;
            }
        }   //same pattern as top
        for(int i=k-1;i<N;i+=2*(k-1)) res.append(s.charAt(i));
        return res.toString();
    }
}
