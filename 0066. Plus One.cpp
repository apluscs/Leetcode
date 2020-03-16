class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int c = 1;
        for(int i = digits.size() - 1; i != -1; --i){
            int sum = digits[i] + c;
            c = sum/10;
            digits[i] = sum % 10;
            if(c == 0)  return digits;  // we are done adding
        }
        digits.insert(digits.begin(),1);    // we know c = 1 at this point, or else it would have left the loop
        return digits;
    }
};
