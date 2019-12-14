class Solution {
    public:
        string getHint(string secret, string guess) {
            unordered_map < char, int > m;
            int bull = 0;
            int cow = 0;
            for (int i = 0; i < guess.length(); i++) {
                if (guess[i] == secret[i])
                    bull++;
                else
                    m[secret[i]]++; //frq of chars in secret
            }
            for (int i = 0; i < guess.length(); i++) {
                if (guess[i] == secret[i]) continue; //don't recount bulls
                if (m.find(guess[i]) != m.end()) {
                    if (m[guess[i]] > 0) { //cow found
                        cow++;
                        m[guess[i]]--;
                    }
                }
            }
            return to_string(bull) + "A" + to_string(cow) + "B";
        }
};
