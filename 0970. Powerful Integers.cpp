class Solution {
  public:
    vector < int > powerfulIntegers(int x, int y, int bound) {
      unordered_set < int > vis;
      int a = 1; // x^0
      while (a <= bound) {
        int b = 1; // y^0
        while (a + b <= bound) {
          vis.insert(a + b); // sometimes there are duplicates, avoid by using a set
          b *= y; // increase the power by 1
          if (y == 1) break;
        }
        a *= x;
        if (x == 1) break; // already processed this value of a
      }

      vector < int > res(vis.begin(), vis.end());
      return res;
    }
};
