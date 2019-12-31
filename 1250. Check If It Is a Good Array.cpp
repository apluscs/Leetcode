class Solution {
    public:
        bool isGoodArray(vector < int > & nums) {
            int N = nums.size(); // just need to see if there are 2 nums that are relativity prime
            int res = nums[N - 1]; // if there are, res will become 1 at some point
            for (int i = N - 2; i != -1; --i)
                res = gcd(res, nums[i]); // cummulative gcd
            return res == 1;
        }

    int gcd(int a, int b) {
        while (b) b ^= a ^= b ^= a %= b;
        return a;
    }
};

class SolutionTLE {
    public:
        bool isGoodArray(vector < int > & nums) {
            int N = nums.size();
            unordered_set < int > gcds; // cummulative gcds of all possible subsets
            for (int i = 0; i != N; i++) {
                if (nums[i] == 1) return true;
                unordered_set < int > toAdd;
                for (int g: gcds) {
                    int curr = gcd(g, nums[i]);
                    if (curr == 1) return true;
                    toAdd.insert(curr);
                }
                for (int g: toAdd)
                    gcds.insert(g);
                gcds.insert(nums[i]);
            }
            return false;
        }

    int gcd(int a, int b) {
        while (b) b ^= a ^= b ^= a %= b;
        return a;
    }
};
