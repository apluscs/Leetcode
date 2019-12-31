class Solution {
    public:
        int titleToNumber(string s) {
            int res = 0;
            for (char c: s) // base 26 conversion
                res = res * 26 - 'A' + 1 + c; // -'A' before you add to guard against overflow
            return res;
        }
};
