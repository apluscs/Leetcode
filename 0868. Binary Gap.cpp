class Solution {
    public:
        int binaryGap(int N) {
            int prev = -1, res = 0;
            for (int i = 0; N != 0; i++) {
                int b = N % 2;
                N >>= 1; //remove rightmost bit
                // cout<<N<<", ";
                if (b == 1) {
                    if (prev != -1) res = max(res, i - prev); //if not first 1, see dist from curr 1 to last seen 1
                    prev = i; //track position of last seen 1
                }
            }
            return res;
        }
};
