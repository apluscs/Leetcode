class Solution {
  public:
    const int dir[8][2] = { {0,1}, {0,-1}, {1,0}, {-1,0}, {1,-1}, {1,1}, {-1,1}, {-1,-1}};
    vector < vector < char >> updateBoard(vector < vector < char >> & board, vector < int > & click) {
      int N = board.size(), M = board[0].size();
      int r = click[0], c = click[1];
      if (board[r][c] == 'M') { // simple case
        board[r][c] = 'X';
        return board;
      }

      queue < pair < int, int >> que;
      que.push(make_pair(r, c));
      while (!que.empty()) {
        pair < int, int > curr = que.front();
        que.pop();
        r = curr.first;
        c = curr.second;
        if (board[r][c] != 'E') continue; // only case you should continue processing
        int count = 0;
        for (auto d: dir) { // each of the 8 neighbors
          int nr = d[0] + r, nc = d[1] + c;
          if (nr < 0 || nc < 0 || nr >= N || nc >= M) continue;
          if (board[nr][nc] == 'M') count++;
        }
        if (count == 0) {
          board[r][c] = 'B';
          for (auto d: dir) { // put all neighbors into queue
            int nr = d[0] + r, nc = d[1] + c;
            if (nr < 0 || nc < 0 || nr >= N || nc >= M || board[nr][nc] != 'E') continue;
            que.push(make_pair(nr, nc));
          }
        } else
          board[r][c] = '0' + count; // '1' through '8'
      }
      return board;
    }
};
