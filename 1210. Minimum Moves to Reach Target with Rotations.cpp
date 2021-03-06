class Solution {
    public:
        int N;
    const int dir[4][2] = { {-1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };
    struct State {
        int r, c, d, moves, id;
        State(int r, int c, int d, int moves): r(r), c(c), d(d), moves(moves), id(r * 10000 + c * 100 + d) {}
    };

    int minimumMoves(vector < vector < int >> & grid) {
        N = grid.size();
        int res = INT_MAX;
        queue < State > que;
        unordered_set < int > vis;
        que.push(State(0, 0, 1, 0)); //original state
        while (!que.empty()) {
            State curr = que.front();
            que.pop();
            int d = curr.d, tr = curr.r, tc = curr.c, hr = tr + dir[d][0], hc = tc + dir[d][1];
            if (out(tr) || out(tc) || out(hr) || out(hc) || grid[hr][hc] == 1 || grid[tr][tc] == 1 || vis.count(curr.id)) continue; //bad conditions
            if (reachEnd(curr)) { //yay!
                res = min(res, curr.moves);
                continue;
            }
            vis.insert(curr.id);
            que.push(State(tr, tc + 1, d, curr.moves + 1)); //shift right
            que.push(State(tr + 1, tc, d, curr.moves + 1)); //shift down
            if (tr == hr && tr != N - 1 && grid[tr + 1][tc] == 0 && grid[hr + 1][hc] == 0) que.push(State(tr, tc, (d + 1) % 4, curr.moves +
            1)); //horizontal? inbound? both cells below are 0? then rotate clockwise
            if (tc == hc && tc != N - 1 && grid[tr][tc + 1] == 0 && grid[hr][hc + 1] == 0) que.push(State(tr, tc, (d + 3) % 4, curr.moves +
            1)); //vertical? inbound? both cells right are 0? rotate ccw
        }
        return res == INT_MAX ? -1 : res; //we were never able to reach the end
    }

    bool out(int curr) {
        return curr < 0 || curr >= N;
    }

    bool reachEnd(State curr) {
        int tr = curr.r, tc = curr.c, hr = tr + dir[curr.d][0], hc = tc + dir[curr.d][1];
        return tr == N - 1 && hr == N - 1 && hc == N - 1 && tc == N - 2;
    }


};
