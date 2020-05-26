class Solution {
public:
    string removeKdigits(string num, int k) {
        
        stack<int> st;
        for(char n:num){
            while(!st.empty() && k>0 && st.top() > n){
                st.pop();
                k--;
            }
            if(st.empty()&&n=='0') continue;    //leading zeros can be ignored
            st.push(n);
        }
        string res="";
        while(!st.empty()){
            res +=st.top();
            st.pop();
        }
        reverse(res.begin(),res.end());
        if(k>=res.length())return "0";
        res.erase(res.begin()+res.size()-k,res.end());  //last segment is non-decreasing, but we still have removals left
        return res;
    }
};
