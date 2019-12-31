class Solution {
    public:
        bool isSubsequence(string s, string t) {
            int i = 0, j = 0, N = s.length(), M = t.length();
            while (i != N && j != M) {
                if (s[i] == t[j]) i++; // now search for next s[i]
                j++;
            }
            return i == N; // found all chars in s in t
        }
};
