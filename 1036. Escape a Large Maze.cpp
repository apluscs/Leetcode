class Solution {
public:
    // key is to stop BFS after 200 levels out, then we know we can move from source outward unrestrictedly, but what if target is blocked off? then try from both source and target
    struct pair_hash{
        template <class T1, class T2>
        size_t operator () (pair<T1, T2> const &pair) const{
            size_t h1 = std::hash<T1>()(pair.first);
            size_t h2 = std::hash<T2>()(pair.second);

            return h1 ^ h2;
        }
    };
    const int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
        unordered_set<pair<int,int>, pair_hash> bad;
        for(auto b:blocked){
            bad.insert(make_pair(b[0],b[1]));
        }
        return solve(source, target, bad) && solve(target,source,bad);
    }
    
    bool solve(vector<int>& source, vector<int>& target, unordered_set<pair<int,int>,pair_hash> bad){
        unordered_set<pair<int,int>,pair_hash> vis;
        queue<pair<int,int>> que;
        que.push(make_pair(source[0],source[1]));
        for(;!que.empty()&&que.size()<=bad.size();){ // more than how much bad blocks could restrict you
            for(int z=que.size();z;--z){
                auto p=que.front();   que.pop();
                int i=p.first,j=p.second;
                // cout<<i<<","<<j<<endl;
                if(p.first==target[0] && p.second==target[1])return true;
                for(auto d:dir){
                    int ni=i+d[0],nj=j+d[1];
                    auto q=make_pair(ni,nj);
                    if(vis.count(q) ||bad.count(q) || ni==-1 || nj==-1 || ni==1e6||nj==1e6) continue;
                    que.push(q);
                    vis.insert(q);
                }
            }
        }
        return !que.empty();    // there are still more cells to reach, that we can reach
    }
};
