class Solution {
    public:
        vector < int > sumZero(int N) {
            int val = 0;
            vector < int > res;
            res.push_back(0);
            for (int i = 1; i < N; i += 2) {
                if (i % 2 == 1) val++; // odd index
                res.push_back(val); // 1, 2, 3
                res.push_back(-val); // -1, -2, -3
            }
            if (N % 2 == 0) {
                res.erase(res.begin() + res.size() - 1); // one extra added --> we are res[N-1] too much
                res[N - 2] -= res[N - 1]; // subtract that from most negative num
            }
            return res;
        }
};
