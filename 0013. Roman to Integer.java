class Solution {
    public static int[] nums=new int[] {0,0,100,500,0,0,0,0,1,0,0,50,1000,0,0,0,0,0,0,0,0,5,0,10};  //quick conversion
    public int romanToInt(String s) {
        int res=0, N=s.length();
        for(int i=0;i<N;i++){
            int curr=nums[s.charAt(i)-'A'];
            if(i!=N-1){
                int next=nums[s.charAt(i+1)-'A'];
                if(next>curr) {
                    res+=next-curr;
                    i++;    //jump over one more
                }
                else res+=curr;
            } else res +=curr;  //always add last number if not already processed
        }
        return res;
    }
}
