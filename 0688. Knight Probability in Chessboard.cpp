class Solution { //DP, but more dimensions. Instead of each entry being a single cell, it is an entire board
    public:
        double knightProbability(int N, int K, int sr, int sc) {
            const vector < vector < int >> dir { { 2, 1 }, {-2, 1 }, { 2, -1 }, {-2, -1 }, { 1, 2 }, {-1, 2 }, { 1, -2 }, {-1, -2 } }; 
            //how a knight can move
            vector < vector < double >> prev(N, vector < double > (N));
            prev[sr][sc] = 1; //100% chance of being here with 0 moves

            for (; K != 0; K--) { //to develop the dp[][] for the next level
                vector < vector < double >> curr(N, vector < double > (N));
                for (int i = 0; i != N; i++)
                    for (int j = 0; j != N; j++) { //for each cell
                        for (int k = 0; k != 8; k++) { //examine the 8 possible
                            int pi = i + dir[k][0], pj = j + dir[k][1]; //where you could have possibly came from
                            if (pi >= 0 && pi < N && pj >= 0 && pj < N) //if in bound
                                curr[i][j] += prev[pi][pj] / 8.0; //probability you reached (pi,pj) in the prev round
                        }
                    }
                prev = curr;
            }
            double res = 0;
            for (vector < double > row: prev)
                for (double d: row) res += d; //sum up whole board
            return res;
        }
};
