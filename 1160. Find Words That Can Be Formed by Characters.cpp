class Solution {
  public:
    int countCharacters(vector < string > & words, string chars) {
      int frq[26] = {
        0
      };
      int res = 0;
      for (char c: chars) frq[c - 'a']++;
      for (string word: words) {
        int wfrq[26] = {
          0
        };
        bool bad = false;
        for (char c: word) wfrq[c - 'a']++; // count frq of letters in word
        for (int i = 0; i != 26; i++)
          if (wfrq[i] > frq[i]) { // unable to make word
            bad = true;
            break;
          }
        if (!bad) res += word.length();
      }
      return res;
    }
};
