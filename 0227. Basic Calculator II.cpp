// So much easier: https://leetcode.com/problems/basic-calculator-ii/discuss/63004/17-lines-C%2B%2B-easy-20-ms
// Let cin handle trimming/parsing for ya


class Solution {
    public:
        int calculate(string str) {
            str = "+" + str + "+";
            int res = 0, N = str.length(), start = 0;
            while (true) {
                int plus = str.find("+", start + 1), minus = str.find("-", start + 1);
                int end = minus != -1 && plus != -1 ? min(minus, plus) : max(minus,
                plus); // if one is not found, do the other; otherwise, choose the one that came first
                string curr = str.substr(start + 1, end - start - 1);
                int op = str[start] == '-' ? -1 : 1;
                res += op * helper(curr);
                start = end; // where we found the op
                if (end == N - 1) break; // reached the '+' at the end
            }
            return res;
        }

    int helper(string str) { // chain of just numbers, spaces, and mult/div ops
        str = "*" + str + "*";
        int res = 1, N = str.length(), start = 0;
        while (true) {
            int mult = str.find("*", start + 1), div = str.find("/", start + 1);
            int end = div != -1 && mult != -1 ? min(div, mult) : max(div, mult);
            string curr = str.substr(start, end - start);
            int cur = stoi(trim(curr));
            int op = str[start] == '/' ? -1 : 1;
            if (op == 1) res *= cur; // op = 1 represents multiplication
            else res /= cur;
            start = end; // where we found the op
            if (end == N - 1) break; // reached the '+' at the end
        }
        return res;
    }

    string trim(string str) { // trim of whitespace
        string res;
        int start = 0;
        while (!(str[start] >= '0' && str[start] <= '9')) start++;
        int end = start; // first nonspace
        while (str[end] >= '0' && str[end] <= '9') end++; // first space after actual string
        return str.substr(start, end - start);
    }
};
