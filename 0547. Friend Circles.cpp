class Solution {
  public:
    int findCircleNum(vector < vector < int >> & mat) {
      int N = mat.size(), res = 0;
      vector < int > par(N, -1);
      for (int i = 0; i != N; i++)
        for (int j = i + 1; j != N; j++) {
          if (mat[i][j] == 0) continue;
          uunion(i, j, par, res);
        }
      for (int p: par)
        res += p == -1 ? 1 : 0; // count #parents (group leaders)
      return res;
    }

  void uunion(int i, int j, vector < int > & par, int & res) { // union is a key word
    int pi = parent(i, par), pj = parent(j, par);
    if (pi != pj)
      par[pi] = pj; // in diff groups, adjust i's parent to be parent of j 

  }

  int parent(int i, vector < int > & par) {
    while (par[i] != -1) i = par[i];
    return i;
  }
};
