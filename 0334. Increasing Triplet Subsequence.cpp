class Solution {
    public:
        bool increasingTriplet(vector < int > & nums) {
            int r1 = INT_MAX, r2 = INT_MAX;
            for (int num: nums) { // <= in case of repeat
                if (num <= r1) r1 = num; // new cand for first part, but existing second part is still saved
                else if (num <= r2) r2 = num; // minimize second elem if you can
                else return true; // found the last
            }
            return false;
        }
};
