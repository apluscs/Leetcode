class Solution {
public:
    int maximumSwap(int num) {
        vector<int> digits;
        while(num != 0){
            digits.push_back(num % 10);
            num /= 10;
        }
        reverse(digits.begin(), digits.end());
        vector<int> right_inds(10, -1);
        for(int i = 0; i != digits.size(); ++i){
            int d = digits[i];
            right_inds[d] = i;
        }
        for(int i = 0; i != digits.size(); ++i){
            int d = digits[i];
            bool found = false;
            for(int j = 9; j != -1; --j){
                if(j <= d) break;   // don't swap with anything <= yourself
                if(right_inds[j] <= i) continue;   // j, which is greater than d, comes before it, so leave it there
                swap(digits[i], digits[right_inds[j]]);
                found = true;
                break;
            }
            if(found)
                break;
        }
        
        int res = 0;
        for(int d : digits){
            res = res * 10 + d;
        }
        return res;
    }
};
