class Solution {
    public:
        void solve(vector < vector < char >> & board) {
            if (board.size() == 0 || board[0].size() == 0) return;
            int N = board.size(), M = board[0].size();
            for (int i = 0; i != N; i++) {
                bfs(board, i, 0); // left side
                bfs(board, i, M - 1); // right
            }
            for (int j = 0; j != M; j++) { // bfs on all bordered cells
                bfs(board, 0, j); // top
                bfs(board, N - 1, j); //bottom
            }

            for (int i = 0; i != N; i++)
                for (int j = 0; j != M; j++)
                    board[i][j] = board[i][j] == '$' ? 'O' : 'X'; // flip 'O' to 'X', keep 'X', and 'D' to 'O'
        }

    void bfs(vector < vector < char >> & board, int si, int sj) {
        int N = board.size(), M = board[0].size();
        if (board[si][sj] != 'O') return;
        queue < pair < int, int >> que;
        que.push(make_pair(si, sj));
        while (!que.empty()) {
            pair < int, int > p = que.front();
            que.pop();
            int i = p.first, j = p.second;
            if (i < 0 || i >= N || j < 0 || j >= M || board[i][j] != 'O') continue;
            board[i][j] = '$'; // hehe, mark as invalid (not surrounded by X)
            que.push(make_pair(i + 1, j));
            que.push(make_pair(i - 1, j));
            que.push(make_pair(i, 1 + j));
            que.push(make_pair(i, j - 1));
        }
    }
};
