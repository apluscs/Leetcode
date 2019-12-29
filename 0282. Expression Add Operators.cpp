class Solution {

    // cur: {string} expression generated so far.
    // pos: {int}    current visiting position of num.
    // cv:  {long}   cumulative value so far.
    // pv:  {long}   previous operand value.
    // op:  {char}   previous operator used.
    public:
        vector < string > addOperators(string num, int target) {
            vector < string > res;
            for (int i = 1; i <= num.size(); i++) {
                string s = num.substr(0, i);
                long cur = stol(s);
                if (to_string(cur).size() != s.size()) continue; // leading zeroes
                dfs(res, num, target, s, i, cur, cur, '#'); // no operator defined.
            }
            return res;
        }

    void dfs(vector < string > & res,
        const string & num,
            const int target, string curr, int pos, long cv, long pv, char op) {
        if (pos == num.size() && cv == target) res.push_back(curr);
        else
            for (int i = pos + 1; i <= num.size(); i++) {
                string temp = num.substr(pos, i - pos);
                long now = stol(temp);
                if (to_string(now).size() != temp.size()) continue; // leading zero
                dfs(res, num, target, curr + '+' + temp, i, cv + now, now, '+'); // cv and pv
                dfs(res, num, target, curr + '-' + temp, i, cv - now, now, '-'); // get updated
                dfs(res, num, target, curr + '*' + temp, i, (op == '-') ? cv + pv - pv * now : ((op == '+') ? cv - pv + pv * now : pv * now), pv * now,
                op); // reverse what we added/subtracted, and now subtract/add the rigth product
            }
    }
};
