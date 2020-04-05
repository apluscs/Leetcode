class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size();
        vector<int> reps(N + 1, -1);
        vector<int> rank(N + 1);
        for(auto edge : edges){
            int a = edge[0], b = edge[1], pa = find(reps, a), pb = find(reps, b);
            if(pa == pb)
                return edge;
            set_union(a, pa, pb, reps, rank);
        }
        return {};
    }
    
    void set_union(int a, int pa, int pb, vector<int>& reps, vector<int>& rank){
        if(rank[pa] >= rank[pb]){
            rank[pa] += rank[pa] == rank[pb] ? 1 : 0; // with rank, doesn't seem to help runtime much
            reps[pb] = pa;
        } else {
            reps[pa] = pb;
        }
    }
    
    int find(vector<int>& reps, int a){
        if(reps[a] == -1) return a;
        reps[a] = find(reps, reps[a]);
        return reps[a];
    }
};
