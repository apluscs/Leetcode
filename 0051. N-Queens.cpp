class Solution {
public:
    vector<bool> rows, cols, up_diag, down_diag;
    vector<string> curr;
    vector<vector<string>> res;
    int N;
    vector<vector<string>> solveNQueens(int N) {
        this->N = N;
        res.clear();  
        curr.clear();    curr.resize(N, string(N,'.'));
        cols.clear();   up_diag.clear();    down_diag.clear();
        cols.resize(N); up_diag.resize(N + N - 1);  down_diag.resize(N + N - 1);
        dfs(0); // up_diag is from bottom left to upper right
        // down_diag is from upper left to bottom right
        return res;
    }
    
    void dfs(int i){
        if(i == N){
            res.push_back(curr);
            return;
        }
        for(int j = 0; j != N; ++j){
            if(cols[j] || up_diag[i+j] || down_diag[j-i + N - 1]) continue; // another queen already in i,j territory
            cols[j] = up_diag[i+j] = down_diag[j-i + N - 1] = true;
            curr[i][j] = 'Q';   // put queen here
            dfs(i + 1);
            curr[i][j] = '.';
            cols[j] = up_diag[i+j] = down_diag[j-i + N - 1] = false;
            
        }
    }
};
