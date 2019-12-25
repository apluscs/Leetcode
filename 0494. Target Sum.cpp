class Solution {
    public:
        vector < int > nums;
        int N, res;

    int findTargetSumWays(vector < int > & A, int S) {
        nums = A;
        N = nums.size();
        res = 0;
        helper(0, S);
        return res;
    }

    void helper(int i, long target) {
        if (i == N) { // reached the end
            if (target == 0) res++; // summed up to S
            return;
        }
        helper(i + 1, target - nums[i]); // if we don't negate nums[i], need nums[i] less target
        helper(i + 1, target + nums[i]); // if we negate nums[i], need nums[i] more target
    }
};
