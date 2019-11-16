class Solution {
    public:
        bool isScramble(string s1, string s2) {
            int N = s1.length();
            // cout<<s1<< " "<<s2<<endl;
            if (s1 == s2) return true;
            int frq[26] = {0};
            for (char c: s1) {
                frq[c - 'a']++;
            }
            for (char c: s2) {
                frq[c - 'a']--;
            }
            for (int f: frq) {
                if (f) return false;
            }
            for (int i = 0; i < N - 1; i++) {
                cout << i << endl;
                if (isScramble(s1.substr(0, i + 1), s2.substr(0, i + 1)) && isScramble(s1.substr(i + 1), s2.substr(i + 1)) ||
                    isScramble(s1.substr(0, i + 1), s2.substr(N - i - 1)) && isScramble(s1.substr(i + 1), s2.substr(0, N - i - 1))
                ) return true;
            }
            return false;
        }
};
