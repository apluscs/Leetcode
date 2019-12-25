class Solution {
    public:
        int evalRPN(vector < string > & tokens) {
            stack < int > st;
            string ops = "+-*/";
            int res = 0;
            for (string str: tokens) {
                int op = ops.find(str); // quick look up using index
                if (op == -1) st.push(stoi(str));
                else {
                    int a = st.top();
                    st.pop();
                    int b = st.top();
                    st.pop();
                    switch (op) { //
                        case (0):
                            st.push(a + b);
                            break;
                        case (1):
                            st.push(b - a);
                            break; // older (left) - newer (right)
                        case (2):
                            st.push(a * b);
                            break;
                        case (3):
                            st.push(b / a);
                            break;
                    }
                }
            }
            return st.top();
        }
};
