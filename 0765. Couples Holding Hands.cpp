class Solution {
public:
    vector<int> reps,pos,rank;
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        reps.resize(n/2);
        rank.resize(n/2);
        fill(reps.begin(),reps.end(),-1);
        pos.resize(n);
        
        for(int i=0;i!=n;++i){
            pos[row[i]]=i/2;
        }
        for(int i=0;i!=n;++i){
            int partner=row[i]%2?row[i]-1:row[i]+1;
            int partner_pos=pos[partner],curr_pos=i/2;
            // cout<<row[i]<<", "<<curr_pos<<", parter="<<partner<<", "<<partner_pos<<endl;
            int a=find(partner_pos),b=find(curr_pos);
            // cout<<i<<", pod="<<b<<endl;
            if(a!=b)set_union(a,b);
            for(int j=0;j!=n/2;++j){
                // cout<<"pod "<<j<<", has rep="<<reps[j]<<endl;
            }   cout<<endl;
        }
        int res=0;
        unordered_map<int,int> frq;
        for(int i=0;i!=n/2;++i){
            int p=find(i);
            frq[p]++;
        }
        for(auto p:frq){
            res+=p.second-1;
        }
        return res;
    }
    
    void set_union(int pa, int pb){
        if(rank[pa] >= rank[pb]){
            rank[pa] += rank[pa] == rank[pb] ? 1 : 0;
            reps[pb] = pa;
        } else {
            reps[pa] = pb;
        }
    }
    
    int find(int a){
        while(reps[a]!=-1)
            a=reps[a];
        return a;
    }
};
