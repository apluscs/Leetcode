class Solution {
    public:
        bool isValid(string s) {
            stack < char > st;
            for (char c: s) {
                if (c == '(' || c == '{' || c == '[') st.push(c); //open
                else if (st.empty()) return false; //surplus of close
                else {
                    char open = st.top();
                    st.pop();
                    if (!(open == '(' && c == ')' || open == '{' && c == '}' || open == '[' && c == ']')) return false; 
                    //needs to match last open one
                }
            }
            return st.empty();
        }
};
