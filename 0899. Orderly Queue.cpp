class Solution {
    public:
        string orderlyQueue(string S, int K) {
            if (K != 1) {
                sort(S.begin(), S.end()); //any permutation is possible, choose the smallest one
                return S;
            }
            int N = S.length();
            string res = S;
            S += S; //less time-intensive way of producing all possible rotations
            for (int i = 0; i != N; i++) {
                string temp = S.substr(i, N); //one possible rotation
                res = min(res, temp);
            }
            return res;
        }
};
