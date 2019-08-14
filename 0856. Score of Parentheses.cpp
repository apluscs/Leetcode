class Solution {
    public:
        int scoreOfParentheses(string S) {
            stack < int > st;
            st.push(0); //st at ith level = the value contained inside the ith level of ( )
            for (char c: S) {
                if (c == '(') st.push(0);
                else {
                    int closed = st.top();
                    st.pop(); //( ) we just closed
                    int prev = st.top();
                    st.pop(); //update prev level
                    st.push(prev + max(2 * closed, 1));
                }
                // cout<<c<<", ";
            }
            return st.top();
        }
};
