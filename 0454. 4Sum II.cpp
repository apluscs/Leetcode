class Solution {
    public:
        int fourSumCount(vector < int > & A, vector < int > & B, vector < int > & C, vector < int > & D) {
            unordered_map < int, int > map;
            int res = 0;
            for (int a: A)
                for (int b: B)
                    map[a + b]++; // all possible 2sums from A,B
            for (int c: C)
                for (int d: D)
                    res += map[-c - d]; // # ways to make negation of c+d with lists A,B
            return res;
        }
};
