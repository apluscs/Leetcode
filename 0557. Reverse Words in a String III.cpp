class Solution {
    public:
        string reverseWords(string s) {
            string curr, res = "";
            istringstream iss(s);
            while (iss >> curr) // curr is valid
                res += reverse(curr) + " ";
            res.erase(res.begin() + res.length() - 1); // last whitespace
            return res;
        }

    string reverse(string & str) {
        int N = str.length();
        for (int i = 0; i != N / 2; i++) {
            int temp = str[i]; // swap, offset by start
            str[i] = str[N - 1 - i];
            str[N - 1 - i] = temp;
        }
        return str;
    }
};
