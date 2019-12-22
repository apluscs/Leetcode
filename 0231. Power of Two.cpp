class Solution {
    public:
        bool isPowerOfTwo(int n) {
            if (n <= 0) return false;
            while (n > 1) { //1 is a power of 2 but odd
                if (n % 2 == 1) return false;
                n >>= 1;
            }
            return true;
        }
};
