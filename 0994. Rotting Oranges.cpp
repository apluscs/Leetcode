class Solution {
    public:

        struct State {
            int time, i, j;
            State(int i, int j, int time): i(i), j(j), time(time) {}
        };
    int N, M;
    int orangesRotting(vector < vector < int >> & grid) {
        int fresh = 0, res = 0;
        N = grid.size();
        M = grid[0].size();
        queue < State > que;
        for (int i = 0; i != N; i++)
            for (int j = 0; j != M; j++) {
                if (grid[i][j] == 1) fresh++; //count #fresh fruits to begin with
                else if (grid[i][j] == 2) que.push(State(i, j, 0)); //put all rotten in cue
            }
        while (!que.empty()) {
            State curr = que.front();
            que.pop();
            int i = curr.i, j = curr.j, time = curr.time;
            if (out(i, j) || grid[i][j] == 3 || grid[i][j] == 0) continue;
            res = max(res, time);
            if (grid[i][j] == 1) fresh--; //another fresh fruit gone
            grid[i][j] = 3; //mark as processed, saves the space that would've been allocated for a vis vector or smthg
            que.push(State(i + 1, j, time + 1));
            que.push(State(i - 1, j, time + 1)); //try all 4 neighbors
            que.push(State(i, j + 1, time + 1));
            que.push(State(i, j - 1, time + 1));
        }
        return fresh == 0 ? res : -1; //if we haven't conquered all fresh, return -1
    }

    bool out(int i, int j) {
        return i == -1 || i == N || j == -1 || j == M;
    }
};
