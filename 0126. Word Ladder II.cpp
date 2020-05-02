class Solution {
public:
    unordered_map<string,vector<string>> adj;   // adj[s] = list of all strings adjacent to string s that gets you closer to end
    unordered_map<string,int> dist;
    vector<vector<string>> res;
    vector<string> path;    // will keep changing
    
    vector<vector<string>> findLadders(string start, string end, vector<string>& bank) {
        unordered_set<string> have(bank.begin(),bank.end());
        queue<string> que;
        que.push(start);
        bool found=false;
        dist[start]=0;
        while(!que.empty()){
            int m=que.size();
            for(int i=0;i!=m;++i){
                string curr=que.front();    
                que.pop();
                string pre=curr;
                for(int j=0;j!=curr.length();++j){
                    int temp=curr[j];
                    for(char op='a';op<='z';++op){
                        curr[j]=op;
                        if(have.count(curr)==0||pre==curr) continue;    // invalid
                        adj[pre].push_back(curr);   // this is a valid neighbor
                        if(dist.count(curr)) continue;  // already visited curr
                        dist[curr]=dist[pre]+1;
                        if(curr==end){
                            found=true;
                        }
                        
                        que.push(curr);
                    }
                    // cout<<endl;
                    curr[j]=temp;
                }
            }
            if(found) break;    // have all connections to end
        }
        // for(auto p:adj){
        //     cout<<p.first<<": ";
        //     for(auto q:p.second) cout<<q<<",";
        //     cout<<endl;
        // }
        backtrack(start,end);
        return res;
    }
    
    void backtrack(string curr, string end){
        // cout<<curr<<" ";
        if(curr==end){
            // cout<<endl;
            path.push_back(curr);
            res.push_back(path);
            path.pop_back();
            return;
        }
        path.push_back(curr);
        
        for(string t:adj[curr]){
            if(dist[t] != dist[curr]+1) continue;   // only visit those that will get you closer to your goal(end)
            backtrack(t,end);
        }
        path.pop_back();
    }
};
