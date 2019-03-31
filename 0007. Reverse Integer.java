class Solution {
    public int reverse(int num) {
        long res=0;
        while(num!=0){
            res=res*10+num%10;  //shift all of res over one place, append new digit
            num/=10;
        }
        if(res>Integer.MAX_VALUE ||res<Integer.MIN_VALUE) return 0; //in case of overflow
        return (int)res;
    }
}
