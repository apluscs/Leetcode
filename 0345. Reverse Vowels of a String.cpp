class Solution {
    public:
        string reverseVowels(string s) {
            vector < int > inds;
            for (int i = s.length() - 1; i != -1; i--) {
                char c = s[i];
                if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U') inds.push_back(
                i); // indexes of vowels
            }
            reverse(s, inds);
            return s;
        }

    void reverse(string & str,
        const vector < int > & inds) {
        int N = inds.size();
        for (int i = 0; i != N / 2; i++) {
            int a = inds[i], b = inds[N - 1 - i]; // reverse chars at these indexes
            char temp = str[a];
            str[a] = str[b];
            str[b] = temp;
        }
    }
};
