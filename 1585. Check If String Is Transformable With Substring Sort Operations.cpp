class Solution {
public:
  bool isTransformable(string s, string t) {
    int n=s.length();
    vector<vector<int>> inds(10);
    vector<int> counts(10);
    for(int i=0;i!=n;++i){
      inds[s[i]-'0'].push_back(i);
    }
    for(char d:t){
      int c=d-'0';
      if(counts[c]==inds[c].size())return false;  // t has too many of c
      for(int i=0;i!=c;++i){
        if(counts[i]<inds[i].size() &&inds[i][counts[i]] <=inds[c][counts[c]])return false;
      // the next occurence of i in t must come before the current position of c in s, since i<c and i cannot advance beyond c         
      }
      counts[c]++;
    }
    return true;
  }
};
