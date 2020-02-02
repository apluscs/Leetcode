class Solution {
  public:
    int minAddToMakeValid(string str) {
      int not_open = 0, not_closed = 0;
      for (char c: str) {
        if (c == '(') not_closed++; // for each extra '(', add ')' after it somewhere
        else if (not_closed > 0) not_closed--;
        else not_open++; // surplus of ')', need '(' before this point
      }
      return not_closed + not_open;
    }
};
