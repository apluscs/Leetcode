class Solution {
    public:

        static bool compar(string & a, string & b) {
            return a.length() > b.length(); // descending order of length
        }

    int findLUSlength(vector < string > & strs) {
        unordered_map < string, int > frq;
        for (string s: strs) frq[s]++;
        strs.clear();
        for (pair < string, int > p: frq) strs.push_back(p.first);
        sort(strs.begin(), strs.end(), compar);
        int N = strs.size();
        for (int i = 0; i != N; i++) {
            if (frq[strs[i]] != 1) continue; // multiple of this string, so can't be uncommon to each other
            int j = 0;
            for (; j != i; j++)
                if (isSubsequence(strs[i], strs[j])) break;
            if (j == i) return strs[i].length(); // traversed all longer strings, all are compatible
        }
        return -1;
    }

    bool isSubsequence(string s, string t) { // if s is a subseq of t
        int i = 0, j = 0, N = s.length(), M = t.length();
        while (i != N && j != M) {
            if (s[i] == t[j]) i++; // now search for next s[i]
            j++;
        }
        return i == N; // found all chars in s in t
    }



};
