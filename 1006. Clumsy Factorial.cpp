class Solution {
  public:
    int clumsy(int N) {
      if (N < 1) return 0;
      int res = get_first_three(N) + N--; // first one is different because the sign is positive
      while (N > 0)
        res += -get_first_three(N) + N--; // if N is ever too small, it will just add 0
      return res;
    }

  int get_first_three(int & N) {
    int res;
    if (N >= 3) {
      res = N * (N - 1) / (N - 2);
      N -= 3;
    } else { // either 1 or 2
      res = N;
      N = 0;
    }
    return res;
  }
};
