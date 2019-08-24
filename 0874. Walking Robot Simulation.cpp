class Solution {
    public:
        const int dir[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, {-1, 0 } };
    int robotSim(vector < int > & commands, vector < vector < int >> & obstacles) {
        int res = 0, x = 0, y = 0, d = 0;
        unordered_set < int > set(obstacles.size());
        for (vector < int > obs: obstacles) set.insert(obs[0] * 30000 + obs[1]);
        for (int com: commands) {
            if (com == -2) d = (d - 1 + 4) % 4; //turn left
            else if (com == -1) d = (d + 1) % 4; //turn right
            else {
                int nx = x, ny = y;
                for (int i = 1; i <= com; i++) {
                    nx += dir[d][0];
                    ny += dir[d][1];
                    if (set.count(nx * 30000 + ny)) {
                        nx -= dir[d][0];
                        ny -= dir[d][1]; //go back to pre-obstacle pos
                        break;
                    }
                }
                //no obstacle in new position (nx,ny)
                x = nx;
                y = ny;
            }
            // cout<<d<<", "<<x<<", "<<y<<endl;
            res = max(res, x * x + y * y);
        }
        return res;
    }
};
