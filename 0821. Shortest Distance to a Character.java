class Solution {
    public:
        vector < int > shortestToChar(string str, char C) {
            int N = str.length(), dist = 10009; //dist starts at > max value res[i] could be
            vector < int > res(N); //each has the initialized value of 0
            for (int i = 0; i != N; i++) {
                if (str[i] == C) dist = 0;
                res[i] = dist++; //increase dist going right
            }
            for (int i = N - 1; i != -1; i--) { //dist is now one larger than res[N-1]
                if (str[i] == C) dist = 0;
                res[i] = min(res[i], dist++); //check if dist from C to right is less than dist from C to left
            }
            return res;
        }
};
