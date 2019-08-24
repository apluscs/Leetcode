class Solution {
    public:
        int minEatingSpeed(vector < int > & piles, int H) {
            int low = 1, high = 1000000000;
            while (low <= high) {
                int K = (low + high) >> 1;
                // cout<<K<<'\t';
                if (able(K, H, piles)) high = K - 1; //we can try less speed
                else low = K + 1; //need to eat faster!
            }
            return low;
        }

    bool able(int K, int H, vector < int > & piles) {
        int hrs = 0;
        for (int p: piles) {
            hrs += (p + K - 1) / K; //basically divides by K and rounds up
            if (hrs > H) return false;
        }
        return true;
    }
};
