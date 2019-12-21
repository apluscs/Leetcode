class Solution {
    public:
        unordered_set < string > res;
    int minLen = INT_MAX, bLeft, bRight;
    vector < string > removeInvalidParentheses(string str) {
        pair < int, int > bad = countBad(str);
        bLeft = bad.first;
        bRight = bad.second;
        helper(str, 0, 0, 0);
        vector < string > ress;
        for (string s: res) ress.push_back(s);
        return ress;
    }

    void helper(string str, int i, int remLeft, int remRight) {
        int N = str.length();
        if (remLeft == bLeft && remRight == bRight) {
            pair < int, int > bad = countBad(str);
            if (bad.first != 0 || bad.second != 0) return; //removed the wrong indexes; this str is bad
            if (N < minLen) {
                res.clear(); //clear all longer strings
                minLen = N;
            }
            if (N == minLen) {
                res.insert(str);
                return;
            }
        }
        if (i == N) return;
        if (str[i] == '(' && remLeft < bLeft) { //still need to remove more (, found a candidate
            helper(str.substr(0, i) + str.substr(i + 1), i, remLeft + 1, remRight);
        } else if (str[i] == ')' && remRight < bRight) { // same logic, just with )
            helper(str.substr(0, i) + str.substr(i + 1), i, remLeft, 1 + remRight);
        }
        helper(str, i + 1, remLeft, remRight); //always try pushing off removal to later indexes
    }

    pair < int, int > countBad(string str) {
        pair < int, int > res;
        int left = 0, right = 0;
        for (char c: str) {
            if (c == '(') left++;
            else if (c != ')') continue; //everything after this is guaranteed )
            else if (left == 0) right++; //no left to match this right
            else left--; //one left gets cleared
        }
        return make_pair(left, right);
    }
};
