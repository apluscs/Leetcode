// so much more elegatn: https://leetcode.com/problems/validate-stack-sequences/discuss/197685/C%2B%2BJavaPython-Simulation-O(1)-Space

class Solution {
  public:
    bool validateStackSequences(vector < int > & pushed, vector < int > & popped) {
      stack < int > st;
      int N = pushed.size(), i = 0, j = 0; // is a ptr for pushed, j is a ptr for popped

      while (i < N || j < N) {
        while (i < N && pushed[i] != popped[j])
          st.push(pushed[i++]);
        if (i < N)
          st.push(pushed[i++]); // push first one that is popped[j]
        if (!st.empty() && st.top() != popped[j])
          return false; // next one that should be popped was pushed too early
        while (j < N && !st.empty() && st.top() == popped[j]) {
          int top = st.top();
          st.pop();
          j++; // pop all those that you can 
        }
      }
      return st.empty();
    }
};
