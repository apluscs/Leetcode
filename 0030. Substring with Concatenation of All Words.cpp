class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        if(words.empty()) return {};
        int n=s.length(),m=words.size(),k=words[0].length();
        unordered_map<string,int> need;
        vector<int> res;
        
        for(string w:words)need[w]++;
        for(int i=0;i<=n-m*k;++i){
            unordered_map<string,int> have;
            bool bad=false;
            for(int j=0;j!=m;++j){
                string curr=s.substr(i+j*k,k);  // current word
                if(have[curr]<need[curr]){
                    have[curr]++;
                }else{
                    bad=true;
                    break;
                }
            }
            if(!bad) res.push_back(i);
        }
        return res;
    }
};
