class Solution {
public:
    string freqAlphabets(string s) {
        int h=s.find('#'), i=0, N=s.length();
        string res="";
        while(i!=N)
            if(h!=-1 && h-i==2){    // character j-z
                int num=(s[i]-'0')*10+s[i+1]-'0';   // convert to int
                i=h+1;  // after the '#'
                res+= (char)(num+'a'-1);
                h=s.find("#",i);
            }else{
                int num=s[i]-'0';
                res+= (char)(num+'a'-1);
                i++;
            }
        return res;
    }
};
