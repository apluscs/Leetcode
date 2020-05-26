class Solution {  // just simulate
public:
    int numSteps(string s) {
        int res = 0;
        while(s != "1"){
            if(s.back() == '0')
                s.pop_back();
            else{
                add_one(s);
            }
            // cout << s << endl;
            res++;
        }
        return res;
    }
    
    void add_one(string& s){
        int N = s.length(), i = N - 1;
        while(i != 0){
            if(s[i] == '0') break;
            i--;
        }
        if(i == 0){
            string res = "1";
            for(int j = 0; j != N; j++)
                res += "0";
            s = res;
            return;
        }
        s[i] = '1';
        for(int j = i + 1; j < N; ++j)
            s[j] = '0';
    }
};
