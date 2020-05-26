class Solution {
public:
    vector<pair<int,int>> open;
    bool done;
    void solveSudoku(vector<vector<char>>& board) {
        open.clear();   done = false;
        int N = board.size(), M = board[0].size();
        for(int i = 0; i != N; ++i)
            for(int j = 0; j != M; ++j)
                if(board[i][j] == '.')
                    open.push_back(make_pair(i,j)); // track each open cell

        dfs(board,0);
    }
   
    void dfs(vector<vector<char>>& board, int o){
        if(o == open.size()){
            done = true;    // global, will end other unnecessary function calls
        }
        if(done) return;
        int i = open[o].first, j = open[o].second;
        for(char c = '1'; c <= '9'; ++c){
            if(placable(c, i, j, board)){
                board[i][j] = c;
                dfs(board, o + 1);
                if(done) return;
                board[i][j] = '.';
            }
        }
       
    }
   
    bool placable(char c, int i, int j, vector<vector<char>>& board){
        for(int k = 0; k != 9; ++k){
            if(board[i][k] == c) return false;  // check row and column
            if(board[k][j] == c) return false;
        }
        i = (i/3) * 3; j = (j/3) * 3;   // upper left corner of square
        for(int k = 0; k != 3; ++k)
            for(int l = 0; l != 3; ++l)
                if(board[i + k][j + l] == c)
                    return false;
            
        return true;
    }
};
