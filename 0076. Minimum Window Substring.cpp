class Solution {
public:
    string minWindow(string s, string t) {
        if(t=="") return "";
        int n=s.length(),i=0,j=0,count=0;  // i to j inclusive
        unordered_map<char,int> need,have;
        for(char c:t){
            need[c]++;
            count++;    // if could==0, we've made a valid window
        }
        pair<int,int> r=make_pair(0,INT_MAX);

        while(j!=n){
            while(j!=n&&count!=0){  // expansion before contraction = cleaner code
                char c=s[j++];
                if(need[c]==0) continue;
                if(have[c]<need[c]) count--;    // making progress
                have[c]++;
                // cout<<j<<endl;
            }
            while(count==0){   
                if(r.second-r.first>j-i){
                    if(j!=i)r=make_pair(i,j);
                }
                char c=s[i++];  // getting kicked out
                if(need[c]==0)continue;
                if(have[c]==need[c])count++;
                have[c]--;
            }
            while(i!=n&&need[s[i]]==0){ // getting rid of fluff
                i++;
            }
            // cout<<res<<", i="<<i<<", j="<<j<<endl;
        }
        if(r.second==INT_MAX) return "";
        return s.substr(r.first,r.second-r.first);
    }
};
