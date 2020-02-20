class Solution {
  public:
    vector < vector < int >> matrixReshape(vector < vector < int >> & nums, int R, int C) {
      int N = nums.size(), M = nums[0].size();
      if (R * C != N * M) return nums; // reshape not possible
      vector < vector < int >> res(R, vector < int > (C));
      for (int i = 0; i != R; ++i)
        for (int j = 0; j != C; ++j) {
          int id = i * C + j; // index if res was a 1d array
          res[i][j] = nums[id / M][id % M]; // break up this index in terms of nums' dimensions
        }
      return res;
    }
};
