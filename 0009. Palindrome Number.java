class Solution {
    public boolean isPalindrome(int num) {
        if(num<0) return false; //negatives are never palindromes
        int[] dts=new int[12];  int i=0;
        while(num!=0){
            dts[i++]=num%10;    //split num into digits
            num/=10;
        }
        for(int j=i/2;j!=i;j++) //digit across middle line (reflection) must be the same
            if(dts[i-j-1]!=dts[j]) return false;
        return true;
    }
}
