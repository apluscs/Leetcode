class Solution {
    public:
        string convertToTitle(int N) {
            string res = "";
            while (N != 0) {
                N--; // why is this necessary?
                res = (char)(N % 26 + 'A') + res; // in order of least to most significance
                N /= 26;
            }
            return res;
        }
};
