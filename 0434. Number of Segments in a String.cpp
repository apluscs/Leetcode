class Solution {
    public:
        int countSegments(string s) {
            istringstream iss(s);
            int res = 0;
            string junk;
            while (iss >> junk)
                res++;
            return res;
        }
};
