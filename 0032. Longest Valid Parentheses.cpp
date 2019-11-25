class Solution {
    public:
        int longestValidParentheses(string s) {
            int N = s.length(), res = 0, left = 0, right = 0;
            for (int i = 0; i != N; i++) { //go forwards
                if (s[i] == '(') left++;
                else right++;
                if (right == left) res = max(res, right + left); //should be 2*right = 2*left
                else if (right > left) right = left = 0; //invalidated substring, start oer
            }
            left = right = 0;
            for (int i = N - 1; i != -1; i--) {
                if (s[i] == '(') left++;
                else right++;
                if (right == left) res = max(res, right + left); //basically whenever you have a perfect balance  
                else if (right < left) right = left = 0;
            }
            return res;
        }
};

class Solution2 {
    public:
        int longestValidParentheses(string s) {
            int N = s.length(), res = 0, curr = 0;
            stack < int > st; //top = index of last invalid substring
            st.push(-1);
            for (int i = 0; i != N; i++) {
                if (s[i] == '(') st.push(i);
                else {
                    st.pop();
                    if (st.empty()) st.push(i); //indicates surplus of ')', = invalid substring
                    else res = max(res, i - st.top());
                }
                // cout<<res<<" ";
            }
            return res;
        }
};

class Solution1 {
    public:
        int longestValidParentheses(string s) {
            int N = s.length(), res = 0;
            if (N == 0) return 0;
            vector < int > dp(N);
            dp[0] = 0;
            for (int i = 1; i != N; i++) {
                if (s[i] == ')') {
                    if (s[i - 1] == '(') dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2; //add additional 2 (s[i] and s[i-1] make a pair)
                    else {
                        int pind = i - dp[i - 1] - 1; //ind of char right before segment ending right before i
                        if (pind >= 0 && s[pind] == '(') { //s[ind] has a starting ( to complete the pair
                            int ppind = i - dp[i - 1] - 2; //finishing ind of segment ending right before enclosing segment
                            dp[i] = dp[i - 1] + 2 + (ppind >= 0 ? dp[ppind] : 0); //first check bounds
                        }
                    }
                }
                // cout<<dp[i]<<" ";
                res = max(res, dp[i]);
            }
            return res;
        }
};
