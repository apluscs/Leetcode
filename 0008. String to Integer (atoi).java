class Solution {
    public int myAtoi(String s) {
        int i=0, N=s.length();    long res=0; int neg=1;
        while(i<N&&s.charAt(i)==' ') i++;   //skip over all spaces
        if(i<N){    char c=s.charAt(i);
            if(c=='-') neg=-1; //deal with negative sign
            if(c=='-'||c=='+') i++;
        }
        while(i<N){
            char c=s.charAt(i);
            if(c<'0'||c>'9') break; //any non-digit yields 0
            res =res*10+c-'0';
            i++;
            if(res>Integer.MAX_VALUE){
                if(neg==-1) return  Integer.MIN_VALUE;
                return Integer.MAX_VALUE;
            } 
        }
        return neg*(int)res;
    }
}
