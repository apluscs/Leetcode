class Solution {
    public:
        vector < string > words;
    string result;
    bool isSolvable(vector < string > & wrds, string rsult) {
        words = wrds;
        result = rsult;
        vector < int > coeff(100);
        vector < bool > start(100), used(10);
        vector < char > letters;
        bool seen[100] = {
            false
        };
        for (string word: words) {
            // cout<<word<<" ";
            start[word[0]] = true;
            int base = 1;
            for (int i = word.length() - 1; i != -1; i--) {
                coeff[word[i]] += base;
                base *= 10;
                seen[word[i]] = true;
            }
        }
        start[result[0]] = true;
        int base = 1;
        for (int i = result.length() - 1; i != -1; i--) {
            coeff[result[i]] -= base;
            base *= 10;
            seen[result[i]] = true;
        }
        for (int i = 'A'; i <= 'Z'; i++)
            if (seen[i]) letters.push_back(i);

        return helper(start, used, coeff, letters, 0, 0);
    }

    bool helper(vector < bool > & start, vector < bool > & used, vector < int > & coeff, vector < char > & letters, int sum, int lnd) {
        if (lnd == letters.size()) return sum == 0;
        // cout<<letters[lnd]<<" ";
        for (int d = start[lnd] ? 1 : 0; d != 10; d++) {
            if (used[d]) continue;
            used[d] = true;
            if (helper(start, used, coeff, letters, sum + d * coeff[letters[lnd]], lnd + 1))
                return true;
            used[d] = false;
        }
        return false;
    }
};
