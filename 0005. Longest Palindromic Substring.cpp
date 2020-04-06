class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length() == 0) return s;
        string t = "$#";
        for(char c : s)
            t += string(1, c) + "#";
        t += "@";
        // cout << t << endl;
        
        int N = t.length();
        vector<int> dp(N);
        int C = 0, R = 0, res = 0, start;
        for(int i = 1; i != t.length(); ++i){   // manachers algorithm
            // https://www.youtube.com/watch?v=nbTSfrEfo6M
            int mirr = C - i + C;
            if(i < R)
                dp[i] = min(dp[mirr], R - i);
            while(t[i + dp[i] + 1] == t[i - dp[i] - 1])
                dp[i]++;
            if(dp[i] > dp[res]) res = i;
            if(i + dp[i] > R){
                C = i;
                R = i + dp[i];
            }
        }
        s = ""; 
        if(res % 2 == 1){   // on a hash tag
            start = res + 1;
        } else {
            start = res + 2;
        }
        // cout << start << endl;
        for(int i = start; s.length() != dp[res] / 2; i += 2){  // build up second half of answer
            s += t[i];
        }
        string rs = s;
        reverse(rs.begin(), rs.end());  // reverse to get first half
        return rs + (res % 2 == 1 ? "" : string(1,t[res])) + s; // if res is even, length of returned string is odd, 
        // so fetch the middle character
    }
};
