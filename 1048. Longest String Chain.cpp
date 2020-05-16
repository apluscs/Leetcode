class Solution {
public:
    struct compar{
        bool operator () (const string& a, const string& b) const{
            return a.length()<b.length();
        }
    };

    int longestStrChain(vector<string>& words) {
        int n=words.size(),res=0;
        sort(words.begin(),words.end(),compar());
        unordered_map<string,int> dp;
        dp[""]=0;
        for(string word:words){
            int m=word.length(),best=1; // everyone can at least start one
            for(int i=0;i!=m;++i){
                string temp=word;
                temp.erase(i,1);
                best=max(best,dp[temp]+1);
            }
            dp[word]=best;
            // cout<<word<<" "<<best<<endl;
            res=max(res,best);
        }
        return res;
    }
};
