class Solution {
    public:
        int findSubstringInWraproundString(string p) {
            vector < int > letters(26); //tracks longest substring of p ending in each letter
            int N = p.size(), res = 0, len = 0;
            for (int i = 0; i != N; i++) {
                int curr = p[i] - 'a'; //convert to 0-25 range
                if (i != 0 && p[i - 1] != (curr + 25) % 26 + 'a') len = 0; //broke the streak, start anew
                len++;
                if (len > letters[curr]) { //only if you found something longer
                    res += len - letters[curr]; //res already counted letters[curr]; now make up for the new part
                    letters[curr] = len; //ex. if we found bc and later found abc, we would only count 2+ (3-2)=3
                    //or if we already found abc and found bc, we would gain no new info
                }
            }
            return res;
        }
};
