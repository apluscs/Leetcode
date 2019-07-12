class Solution {
    public:
        string lower(string str) {
            string res;
            for (int i = 0; i != str.length(); i++) res += tolower(str[i]);
            return res;
        }
    string mostCommonWord(string para, vector < string > & banned) {
        map < string, int > frq;
        for (string b: banned) frq[b] = -1;
        para += '.';
        int st = 0;
        int max = 0;
        string res;
        for (int i = 0; i != para.length(); i++) {
            char c = para[i];
            // cout<<i<<" "<<st<<endl;
            if (c == ' ' || c == '!' || c == '?' || c == ',' || c == ';' || c == '.' || c == '\'') {
                string word = lower(para.substr(st, i - st > 0 ? i - st : 0));
                // cout<<c<<word<<endl;
                st = i + 1;
                if (word.length() == 0 || frq[word] == -1) continue;
                frq[word]++;
                int ct = frq[word];
                if (ct > max) {
                    max = ct;
                    res = word;
                }
            }
        }
        return res;
    }
};
