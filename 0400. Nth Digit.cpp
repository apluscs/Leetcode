class Solution {
  public:
    int findNthDigit(int N) {
      long digits = 1, pow = 1; // num digits in each batch (1-9, 10-99, etc)
      while (N - 9 * pow * digits > 0) { // pow corresponds with 1, 10, etc.
        N -= 9 * pow * digits;
        pow *= 10;
        digits++;
      } // now pow is lowest number with same digits as N, N is the Nth digit starting with pow
      N--; // base zero indexing
      int num = pow + N / digits; // N/digits is how many numbers after pow it is
      N %= digits; // what digit are you looking for in this num?
      for (int i = digits - 1; i != N; --i) num /= 10; // get that digit!
      return num % 10;
    }
};
