class Solution {
public:
    // vector<short> able;
    int n;
    int end;
    unordered_set<int> have;
    struct pair_hash{
        template <class T1, class T2>
        size_t operator () (pair<T1, T2> const &pair) const{
            size_t h1 = std::hash<T1>()(pair.first);
            size_t h2 = std::hash<T2>()(pair.second);

            return h1 ^ h2;
        }
    };
    unordered_set<pair<int,int>, pair_hash> vis;
    bool res;
    bool canCross(vector<int>& stones) {
        n=stones.size();
        res=false;
        end=stones[n-1];
        have.insert(stones.begin(),stones.end());
        solve(stones[0]+1,1);
        return res;
    }
    
    void solve(int pos,int k){
        if(pos==end || res){    // short circuit if res is true
            res=true;
            return;
        }
        auto p=make_pair(pos,k);
        if(vis.count(p)) return;   // already visited this state before
        if(have.count(pos)==0 || k<1) return;
        solve(pos+k-1,k-1);
        solve(pos+k,k);
        solve(pos+k+1,k+1);
        vis.insert(p);
    }
};
