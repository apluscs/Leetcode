class Solution {
  public:
    unordered_map < string, int > map;
  int evaluate(string exp) {
    map.clear();
    return helper(exp);
  }

  int helper(string & exp) {
    int i = 0, N = exp.length();
    string comm = getWord(exp, i);
    if (isNumber(comm)) return stoi(exp);
    if (comm == "(add" || comm == "(mult") {
      string e1 = getExpression(exp, i), e2 = getExpression(exp, i);
      int v1, v2;
      v1 = helper(e1); // evaluate the expression
      v2 = helper(e2);
      return comm == "(add" ? v1 + v2 : v1 * v2;
    }
    if (comm == "(let") {
      unordered_map < string, int > temp = map;
      while (true) {
        string
        var = getExpression(exp, i);
        if (i == exp.length()) { // var is actually last expr to return
          int res = helper(var);
          map = temp; // helper will change some map entries, change them back to this scope
          return res;
        }
        string ex = getExpression(exp, i);
        map[var] = helper(ex); // assign value to var
      }

    }
    return map[exp]; // assigned variable
  }

  string getExpression(const string & exp, int & i) {
    if (exp[i] != '(') return getWord(exp, i); // either a var or int
    int j = i + 1, bal = 1;
    while (bal != 0) {
      if (exp[j] == '(') bal++;
      else if (exp[j] == ')') bal--;
      j++;
    }
    string res = exp.substr(i, j - i);
    i = j + 1; // move past the last ')''
    return res;
  }

  string getWord(const string & exp, int & i) {
    int sp = exp.find(" ", i), par = exp.find(")", i);
    int j = sp == -1 ? par : sp; // end of chain, then sp == -1
    if (sp == -1 && par == -1) j = exp.length(); // nothing afterwards
    string res = exp.substr(i, j - i);
    i = j + 1; // next char after the space
    return res;
  }

  bool isNumber(const string & s) { // from STack Overflow
    return !s.empty() && std::find_if(s.begin(),
      s.end(), [](unsigned char c) {
        return !(std::isdigit(c) || c == '-');
      }) == s.end();
  }
};
