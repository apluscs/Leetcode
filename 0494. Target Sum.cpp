class Solution {
    public:

        int findTargetSumWays(vector < int > & nums, int target) {
            int N = nums.size();
            vector < int > prev(2001);
            prev[nums[0] + 1000] = 1;
            prev[-nums[0] + 1000]++; // in the case of 0, these are the same index
            for (int i = 1; i != N; i++) { // for every index in nums
                vector < int > curr(2001);
                for (int j = 0; j != 2001; j++) // traverse thru prev
                    if (prev[j] != 0) {
                        curr[j + nums[i]] += prev[j]; // we can achieve this sum in prev[j] more ways
                        curr[j - nums[i]] += prev[j];
                    }
                prev = curr; // update for next row in dp table  
            }

            return target > 1000 ? 0 : prev[target + 1000];
        }


};

class Solution2 {   // recursion with memoization
    public:
        int N;
    vector < vector < int >> memo;

    int findTargetSumWays(vector < int > & nums, int S) {
        N = nums.size();
        vector < vector < int >> temp(N, vector < int > (2001, -1)); // init all to -1;
        memo = temp;
        return helper(nums, 0, S, 0);
    }

    int helper(vector < int > & nums, int i, int target, int curr) { // returns #ways to get to target if you're at index i with a current sum of curr
        if (i == N)
            return curr == target ? 1 : 0;
        if (memo[i][curr + 1000] == -1) {
            int a = helper(nums, i + 1, target, curr + nums[i]), b = helper(nums, i + 1, target, curr - nums[i]); // try adding & subtracting nums[i]
            memo[i][curr + 1000] = a + b;
        }
        return memo[i][curr + 1000];
    }
};

class SolutionSLOW {
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
