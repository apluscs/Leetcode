class Solution {
    public:
        const string vowels = "aeiouAEIOU";
    string toGoatLatin(string S) {
        string res;
        int N = S.length();
        int st = 0;
        S += ' '; //so that every word ends with a space, easier to code
        string end = "maa";
        while (st < N) {
            int sp = S.find(' ', st); //index of space
            string word = S.substr(st, sp - st); //c++ substr() is diff; second arg is length of substring
            // cout<<word<<' ';
            if (vowels.find(word[0]) == -1) res += word.substr(1, sp - st - 1) + word[0]; //starts with consonant
            else res += word; //starts with vowel
            res += end + ' ';
            end += 'a'; //lengthen maaa everytime
            // cout<<res<<endl;
            st = sp + 1; //new word starts after this space
        }
        res.erase(res.length() - 1, 1); //last char is a space
        return res;
    }
};
