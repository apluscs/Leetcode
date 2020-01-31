class Solution {
  public:
    int countBinarySubstrings(string s) {
      int i = 0, res = 0, N = s.length(), prev = get_length(s, i);
      while (i != N) {
        int curr = get_length(s, i);
        res += min(prev, curr); // bounded by minimum of the two consecutive chains
        prev = curr;
      }
      return res;
    }

  int get_length(string & s, int & i) { // length of chain of chars starting from i
    int N = s.length(), res = 0;
    char base = s[i];
    while (i != N && s[i] == base) {  
      res++;
      i++;  // i will end at first index of char that's not the same as the one in this chain
    }
    return res;
  }
};
