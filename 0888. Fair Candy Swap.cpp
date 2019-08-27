class Solution {
    public:
        vector < int > fairCandySwap(vector < int > & A, vector < int > & B) {
            long diff = 0;
            unordered_set < int > bset(B.size());
            for (int a: A) diff += a;
            for (int b: B) {
                diff -= b;
                bset.insert(b); //track what vals in B
            }
            diff = diff / 2; //difference in values to exchange (a-b)
            for (int a: A)
                if (bset.count(a - diff)) return { a, a - diff }; //find a b such that diff = a-b; b=a-diff
            return {};
        }
};
