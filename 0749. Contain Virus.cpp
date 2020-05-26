class Solution {
public:
    const int dir[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    int n,m,R,res;
    unordered_map<int,int> damage,reps;
    unordered_set<int> in_danger;
    vector<vector<int>> grid;
    
    int containVirus(vector<vector<int>>& f) {
        this->grid=f;
        n=grid.size();
        m=grid[0].size();
        res=0;
        
        while(true){    // whole new board
            R=1;
            damage.clear();
            reps.clear();
            for(int i=0;i!=n;++i){
                for(int j=0;j!=m;++j){
                    if(grid[i][j]!=1 || reps.count(i*50+j))continue;    // already discovered
                    in_danger.clear();
                    dfs(i,j);
                    damage[R]=in_danger.size();
                    R++;
                }
            }
            if(R==1)return res; // no more blobs to be contained
            int worst_blob=1;
            for(auto p:damage){
                // cout<<p.first<<", "<<p.second<<endl;
                if(p.second>damage[worst_blob])worst_blob=p.first;
            }
            
            contain(worst_blob);   
            
            for(int i=0;i!=n;++i){
                for(int j=0;j!=m;++j){
                    if(grid[i][j]!=1 || reps[i*50+j]==0)continue; 
                    for(auto d:dir){
                        int ni=i+d[0],nj=j+d[1],nid=ni*50+nj;
                        // cout<<"adding "<<ni<<" "<<nj<<", from "<<i<<", "<<j<<endl;
                        // cout<<reps.count(nid)<<endl;
                        if(!out(ni,nj)&& grid[ni][nj]==0&&reps[nid]==0){
                            
                            // cout<<reps.count(i*50+j)<<endl;
                            grid[ni][nj]=1;
                        }
                    }
                }
            }
            // for(int i=0;i!=n;++i){
            //     for(int j=0;j!=m;++j){
            //         cout<<grid[i][j]<<" ";
            //     }
            //     cout<<endl;
            // }
            // cout<<endl;
        }
        return 0;
    }

    
    void contain(int worst_blob){
        for(int i=0;i!=n;++i){
            for(int j=0;j!=m;++j){
                if(reps[i*50+j] == worst_blob){
                    grid[i][j]=2;    // wall it up
                    for(auto d:dir){
                        int ni=i+d[0],nj=j+d[1],nid=ni*50+nj;
                        if(!out(ni,nj)&& grid[ni][nj]==0)res++;
                    } 
                }
            }
        }
    }
    
    void dfs(int i,int j){  // floodfill
        reps[i*50+j]=R;
        // cout<<i<<", "<<j<<",, "<<R<<endl;
        // cout<<R<<endl;
        for(auto d:dir){
            int ni=i+d[0],nj=j+d[1],nid=ni*50+nj;
            if(!out(ni,nj)&&grid[ni][nj]==1&&reps.count(nid)==0){   // another undiscovered one in this blob
                dfs(ni,nj);
            }
            else if(!out(ni,nj)&&grid[ni][nj]==0)in_danger.insert(nid);
        }
    }
    
    bool out(int i,int j){
        return i==-1||i==n||j==-1||j==m;
    }
};
