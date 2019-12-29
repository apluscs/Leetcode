class Solution {
    public:
        int calculate(string str) {
            int num = 0;
            long base = 1;
            stack < pair < char, int >> st;
            for (int i = str.length() - 1; i != -1; i--) {
                char c = str[i];
                if (c >= '0' && c <= '9') num += base * (c - '0');
                base *= 10; // build up this num
                else if (c != ' ') {
                    if (base != 1) { // need to make sure we encountered digits
                        st.push(make_pair(' ', num)); // mark this as a num, not char
                        num = 0;
                        base = 1;
                    }
                    if (c == '(') eval(st); // end of ( ) group
                    else st.push(make_pair(c, -1)); // c is ')' or an op
                }
            }
            if (base != 1) st.push(make_pair(' ', num)); // push last num if any
            eval(st);
            return st.top().second;
        }

    void eval(stack < pair < char, int >> & st) {
        int res = 0;
        bool add = true;
        while (!st.empty()) {
            pair < char, int > p = st.top();
            st.pop();
            char c = p.first;
            int num = p.second;
            if (c == ')') break; // reached the 'beginning' of ( ) group
            if (p.first == ' ') res += add ? num : -num; // this is a num
            else add = c == '+'; // save the op
        }
        st.push(make_pair(' ', res)); // condense alll that into one num
    }
};
