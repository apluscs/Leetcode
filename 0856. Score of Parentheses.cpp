class Solution {
    public:
        int scoreOfParentheses(string S) {
            int res = 0, layer = 1, N = S.length();
            for (int i = 0; i != N; i++) {
                char c = S[i];
                if (c == '(') layer << 1; //how many ( ) are around the to-be core
                else {
                    // cout<<c<<", "<<i;
                    layer >> 1;
                    char prev = S[i - 1];
                    if (prev == '(') res += layer; //found a core, adding 2^(layer-1) to res
                }
                // cout<<layer<<'\t';
            }
            return res;
        }
};

class SolutionBadMemory {
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
