class Solution {
    public:
        const int dir[4][2] = { { 0, 1 }, { 1, 0 }, { 0, -1 }, {-1, 0 }, };
        vector < vector < int >> spiralMatrixIII(int R, int C, int r0, int c0) {
            vector < vector < int >> res(R * C);
            res[0] = { r0, c0 };
            int r = r0, c = c0, d = 0, count = 0, vis = 1;
            while (vis != R * C) { //vis tracks how many cells IN THE GRID we stepped on
                // cout<<r<<", "<<c<<endl;
                int rad = count / 2 + 1; //distance need to move in this direction; every two changes of direction, rad++
                for (int subr = 0; subr != rad; subr++) { //how much we moved so far
                    r += dir[d][0];
                    c += dir[d][1]; //move one unit in this direction
                    if (r > -1 && r < R && c > -1 && c < C) //if actually on the grid
                        res[vis++] = { r, c };

                }
                d = (d + 1) % 4; //new direction
                count++; //track how many times we switched direction
            }
            return res;
        }
};
