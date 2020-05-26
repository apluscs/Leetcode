class Solution {    // KMP much faster
public:
    string shortestPalindrome(string s) {
        int M=s.length();
        string t=s;
        reverse(t.begin(),t.end());
        string s_new=s+"#"+t;
        // cout<<s_new;
        int N=s_new.length();
        vector<int>dp(N);
        for(int i=1;i!=N;++i){
            int x=dp[i-1];  // current suffix matches with dp[i-1] of prefix, can we cont?
            while(x >0&&s_new[i] != s_new[x]){
                x=dp[x-1];    // even if you can't continue this one, this suffix matches with dp[x] of the prefix, so try there
            }
            if(s_new[x] == s_new[i]) x++;
            dp[i]=x;
        }   // how much of prefix is a palindrome? indicated by how much of it, reflected, matches it, originally... the reflected part is now at the end, as a "suffix" of s_new
        int x=dp[N-1];
        t=s.substr(x);
        reverse(t.begin(),t.end());
        return t+s;
    }
};


class SolutionSLOW {
public:
    string shortestPalindrome(string s) {
        string t = "$#";
        for(char c:s){
            t+=string(1,c) + "#";
        }
        t+="@";
        int n = t.length(), C = 0, R = 0;
        vector<int>palin(n);
        for(int i=1;i < n - 1;++i){
            int mirr=C+C-i;
            if(i < R)   // use what you already know
                palin[i]=min(palin[mirr],R-i);
            while(t[i+palin[i]+1] == t[i-palin[i]-1]) // expand as much as you can
                palin[i]++;    // then update R, C
            if(i +palin[i] > R){
                R =i+palin[i];
                C=i;
            }
            // int curr=get_remainder(i,palin[i]);
            // best=max(best,curr);
            // if(t[i]!='#')
                // cout<<string(1,t[i])<<" "<<palin[i]<<endl;
        }
        int pos;
        for (int i = n - 2; i; i--) {
            if (i - palin[i] == 1) {
                pos = palin[i];
                break;
            }
        }
        string tail = s.substr(pos); 
        reverse(tail.begin(), tail.end());
        return tail + s;
    }
};
