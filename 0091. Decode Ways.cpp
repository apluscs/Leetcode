class Solution {
    public:
        int numDecodings(string s) {
            int N = s.length();
            if (N == 0 || s[0] == '0') return 0;
            if (N == 1) return 1;
            vector < int > dp(N + 1);
            dp[0] = dp[1] = 1;
            for (int i = 2; i != N + 1; i++) { //indices in dp
                bool isZero = s[i - 1] == '0', isValid = valid(s, i - 2); //s is still base 0
                if (!isZero && isValid) dp[i] = dp[i - 1] + dp[i - 2]; //decode this one indiv, or this+prev as one char
                else if (!isZero && !isValid) dp[i] = dp[i - 1]; //can only decode this indiv
                else if (isZero && isValid) dp[i] = dp[i - 2]; //#ways to decode without last two letters
                else return 0; //can't decode indiv, can't decode paired with prev
                // cout<<dp[i]<<" "<<endl;
            }
            return dp[N];
        }

    bool valid(string s, int ind) { //can you make a valid encoding with these two chars?
        int res = stoi(s.substr(ind, 2));
        // cout<<"res: "<<res<<endl;
        return res >= 1 && res <= 26 && s[ind] != '0';

    }
};
