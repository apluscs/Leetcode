class Solution {
    public boolean lemonadeChange(int[] bills) {
        int fives = 0;  int tens = 0;
        for(int n: bills){
            if(n==5){fives++;}
            else if(n==10){
                fives--;    tens++;
                if(fives<0){return false;}
            }
            else{   //$20 paid
                tens--;
                if(tens<0){ //dipped too low
                    tens++;  
                    fives = fives-3;
                    if(fives<0){return false;}
                }
                else{fives = fives-1;
                    if(fives<0){return false;}
                }
            }
        }
        return true;
    }
}
