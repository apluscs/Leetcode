class Solution {
    public:
        string shiftingLetters(string str, vector < int > & shifts) {
            long sft = 0; //store what the current shift is
            for (int i = shifts.size() - 1; i != -1; i--) {
                sft = (sft + shifts[i]) % 26; //add shifts to current shift, make sure it's under 26
                str[i] = (str[i] - 'a' + sft) % 26 + 'a'; //reindex char to 0-25, add shift, make sure it's under 26, 
                //reindex back to letter
            }
            return str;
        }
};
