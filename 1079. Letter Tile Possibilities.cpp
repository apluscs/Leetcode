class Solution {
public:
    unordered_set<string> vis;
    int n,m;
    string s,curr;
    int numTilePossibilities(string tiles) {
        s=tiles;
        n=tiles.length();
        curr="";
        dfs(0);
        // for(string t:vis)cout<<t<<endl;
        return vis.size()-1;    // empty string
    }
    
    void dfs(int i){  // all 2^n combination
        if(i==n){ 
            if(!vis.count(curr)){ // no more letters to choose from, permute this combination
                m=curr.length();
                permute(0);  // haven't seen this string before
            }
            return;
        }
        dfs(i+1);
        curr+=s[i];
        dfs(i+1);
        curr.pop_back();
    }
    
    void permute(int i){
        if(i==m){
            vis.insert(curr);
            return;
        }
        for(int j=i;j!=m;++j){
            swap(curr[i],curr[j]);
            permute(i+1);
            swap(curr[i],curr[j]);
        }
    }
};
