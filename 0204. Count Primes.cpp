class Solution {
    public:
        int countPrimes(int N) {
            int res = 0;
            bool * arr = new bool[N];
            for (int i = 2; i < N; i++) arr[i] = false;
            for (int i = 2; i < N; i++) {
                if (arr[i]) continue; // marked as composite
                res++;
                for (int j = i + i; j < N; j += i) arr[j] = true; //mark all multiples as composite
            }
            return res;
        }
};
