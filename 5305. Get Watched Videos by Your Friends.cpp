class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& vids, vector<vector<int>>& friends, int id, int L) {
        int N=vids.size(), M=friends.size(), lev=0;
        queue<int> que;
        vector<bool> vis(M);
        que.push(id);
        while(lev != L){
            int sz=que.size();
            for(int i=0;i!=sz;i++){
                int curr=que.front();   que.pop();  
                if(vis[curr]) continue;
                vis[curr]=true;
                for(int fr: friends[curr])
                    que.push(fr);   // push all friends of curr
            }
            lev++;
        }   // now que has all friends at level L
        
        unordered_map<string, int> mp;    
        vector<string> res;   
        map<int, vector<string>> mp2;   // each frequency to list of vids with that frq
        while(!que.empty()){
            int curr=que.front();   que.pop();  
            if(vis[curr]) continue;
            vis[curr]=true;
            for(string v: vids[curr])
                mp[v]++;    // count frq of each title
        }
        for(pair<string,int> p:mp)
            mp2[p.second].push_back(p.first);   // frq --> vid title
        for(auto p: mp2){
            sort(p.second.begin(), p.second.end()); // alphabetical
            for(auto v: p.second)  // string
                res.push_back(v);
        }
        return res;
    }
};
