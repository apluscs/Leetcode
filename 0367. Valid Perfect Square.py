class Solution {
public:
    bool isPerfectSquare(int num) {
        for(long i = 1; true; ++i){
            long sq = i * i;
            if(sq == num)
                return true;
            if(sq > num)    // went beyond num, so we can stop here
                return false;
        }
        return false;
    }
};
