class Solution {
  public:
    int minFlips(int A, int B, int C) {
      int res = 0;
      for (int i = 0; i != 31; i++) { // 31 bits
        int c = C % 2, a = A % 2, b = B % 2; // get the rightmost bit from each 
        if (c == 1) {
          if (a == 0 && b == 0) res++; // flip a or b to 1
        } else { // c=1
          if (a == 1 && b == 1) res += 2; // need to flip both to 0
          else if (a == 1 || b == 1) res++; // only one needs to be flipped
        }
        C >>= 1;
        A >>= 1;
        B >>= 1; // move along
      }
      return res;
    }
};
