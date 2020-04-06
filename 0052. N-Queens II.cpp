class Solution {
public:
    vector<bool> cols, up_diag, down_diag;
    int N, res;
    
    int totalNQueens(int N) {
        this->N = N;
        res = 0;
        cols.clear();   up_diag.clear();    down_diag.clear();
        cols.resize(N); up_diag.resize(N + N - 1);  down_diag.resize(N + N - 1);
        dfs(0); // up_diag is from bottom left to upper right
        // down_diag is from upper left to bottom right
        return res;
    }
    
    void dfs(int i){
        if(i == N){
            res++;
            return;
        }
        for(int j = 0; j != N; ++j){
            if(cols[j] || up_diag[i+j] || down_diag[j-i + N - 1]) continue; // another queen already in i,j territory
            cols[j] = up_diag[i+j] = down_diag[j-i + N - 1] = true;
            dfs(i + 1);
            cols[j] = up_diag[i+j] = down_diag[j-i + N - 1] = false;
        }
    }
};
