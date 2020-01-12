class Solution {
public:
    vector<int> getNoZeroIntegers(int N) {
        for(int i=N/2;i !=0;i--){   // try all possible two sums of N
            int j=N-i;  
            if(containsZero(i) || containsZero(j)) continue;
            return {i,j};   // any one works
        }
        return {};
    }
    
    bool containsZero(int num){
        while(num!=0){
            int d=num%10;   // keep checking last digit of num
            if(d==0) return true;
            num/=10;
        }
        return false;
    }
};
