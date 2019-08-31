class Solution {
    public:
        vector < string > findAndReplacePattern(vector < string > & words, string pattern) {
            vector < string > res;
            int N = pattern.length();
            for (string word: words) 
                if (isPattern(word, pattern, N)) res.push_back(word);
            return res;
        }

    bool isPattern(string word, string key, int N) {
        unordered_map < char, char > wtok, ktow; //maps each char in w to its buddy in key, and vice versa
        // cout<<wtok['.']<<'.'<<endl;
        for (int i = 0; i != N; i++) {
            char w = word[i], k = key[i];
            if (wtok.count(w) != 0 && wtok[w] != k || ktow.count(k) != 0 && ktow[k] != w)
                return false; //if w has already been matched and not to k, same for the other way around
            wtok[w] = k; //no inconsistency, so add to map
            ktow[k] = w; //same for other relationship
        }
        return true;
    }
};
