class Solution {
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
