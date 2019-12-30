class Solution {
    public:
        vector < int > pathInZigZagTree(int label) {
            vector < int > res;
            int two = 1;
            while (two <= label) two <<= 1; // two is lowest power of 2 > label
            while (label != 0) {
                res.push_back(label);
                int p = two - label + two / 2 - 1; // if this row was reflected, p would be where label is
                two >>= 1;
                label = p / 2; // parent is always half of this num (in a normal tree)
            }
            reverse(res.begin(), res.end());
            return res;

        }
};
