class Solution {
    public static String[][] nums=new String[][]{{"I","V"},{"X","L"},{"C","D"},{"M"}};  //fast conversion
    public String intToRoman(int num) {
        int plc=0; StringBuilder res=new StringBuilder();
        while(num!=0){
            res.insert(0,gen(plc++,num%10));    //must add higher placed digits to the front
            num/=10;
        }
        return res.toString();
    }
    public String gen(int plc,int curr){
        if(curr==4) return nums[plc][0]+nums[plc][1];
        if(curr==9) return nums[plc][0]+nums[plc+1][0];
        String res="";
        if(curr>=5) res=nums[plc][1];
        curr%=5;
        for(int i=0;i<curr;i++) res+=nums[plc][0];
        return res;
    }
}
