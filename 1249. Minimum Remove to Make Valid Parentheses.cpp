class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string a=remove_extra(s,'(',')');
        // cout<<a<<endl;
        reverse(a.begin(),a.end());
        a=remove_extra(a,')','(');  // flipped, so that rights come before left, status is also reversed
        reverse(a.begin(),a.end());
        return a;
        
    }
    string remove_extra(string& s, char x, char y){ // x is pos, y is neg
        int n=s.length(),bal=0;
        string res="";
        for(char c:s){
            if(c!=y){
                res+=c;
                bal+=c==x;
            }else{
                bal--;
                if(bal<0){
                    bal=0;
                    continue;   // don't add ) because we dont' have enough left to pair with
                }
                res+=c;
            }
        }
        return res;
    }
};
