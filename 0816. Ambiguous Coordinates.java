class Solution {
    public:
        vector < string > ambiguousCoordinates(string str) {
            vector < string > res;
            str = str.substr(1, str.length() - 2); //remove parentheses cuz they're ANNOYING
            int N = str.length();
            for (int i = 1; i != N; i++) { //all possible places to split str into 2 halves
                string fr = str.substr(0, i), bk = str.substr(i);
                // cout<<fr<<" "<<bk<<endl;
                if (!valid(fr) || !valid(bk)) continue;
                for (string pfr: decString(fr))
                    for (string pbk: decString(bk))
                        res.push_back('(' + pfr + ", " + pbk + ')');
            }
            return res;
        }

    vector < string > decString(string str) {
        vector < string > res;
        int N = str.length();
        if (N == 1 || str[N - 1] == '0') { //just one string; ends in 0 --> must be a multiple of 10
            res.push_back(str);
            return res;
        }
        if (str[0] == '0') { //starts with 0 --> must be a decimal  < 1
            res.push_back("0." + str.substr(1));
            return res;
        }
        for (int i = 1; i != N; i++) { //all places to insert a decimal
            string fr = str.substr(0, i), bk = str.substr(i);
            res.push_back(fr + '.' + bk);
        }
        res.push_back(str);
        return res;
    }
    bool valid(string str) { //ex. 020 can't work, any single digit works
        return str.length() == 1 || str[0] != '0' || str[str.length() - 1] != '0';
    }
};
