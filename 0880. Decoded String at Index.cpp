class Solution {
    public:
        string decodeAtIndex(string S, int K) {
            long len = 0;
            int N = S.size();
            for (char c: S) {
                if (c >= '0' && c <= '9') len *= c - '0';
                else len++; //count total size of the decoded string
            }
            for (int i = N - 1; i != -1; i--) {
                K %= len; //if K > len, that means the segment up to i is repeated, need to mod it to 
                char c = S[i];
                if (c >= '0' && c <= '9') len /= c - '0'; //get length of repeated segment before this char
                else { //found a letter
                    if (K == 0) return string(1, c);
                    len--;
                }
            }
            return "";
        }
};
