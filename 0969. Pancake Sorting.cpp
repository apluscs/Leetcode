class Solution {
  public:
    vector < int > pancakeSort(vector < int > & A) {
      vector < int > res;
      for (int N = A.size(); N != 0; N--) { // each possible value in A
        int i = A.size() - 1;
        for (; i != -1; --i)
          if (A[i] == N) break;
        reverse(A.begin(), A.begin() + i + 1); // move value N to pos=0
        res.push_back(i + 1); // record what you did
        reverse(A.begin(), A.begin() + N); // move front to where its supposed ot be
        res.push_back(N);
      }
      return res;
    }
};
