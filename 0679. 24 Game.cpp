class Solution {
    public:
        bool judgePoint24(vector < int > & nums) {
            vector < double > curr;
            for (int n: nums) curr.push_back(n); //convert into doubles
            return helper(curr);
        }


    bool helper(vector < double > nums) {
        int N = nums.size();
        if (N == 0) return false;
        if (N == 1) return abs(nums[0] - 24) < 1e-3;

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) { //we will try some operation with i and j
                if (i == j) continue;
                vector < double > curr;
                for (int k = 0; k != N; k++) //insert everything besides i and j
                    if (k != i && k != j) curr.push_back(nums[k]);
                for (int k = 0; k != 4; k++) {
                    if (k < 2 && j > i) continue; //already done when and i and j were swapped
                    if (k == 0) curr.push_back(nums[i] + nums[j]);
                    if (k == 1) curr.push_back(nums[i] * nums[j]);
                    if (k == 2) curr.push_back(nums[i] - nums[j]);
                    if (k == 3) //try all possible ops, check for /0 ofc
                        if (nums[j] != 0) curr.push_back(nums[i] / nums[j]);
                        else continue;
                    if (helper(curr)) return true;
                    curr.erase(curr.begin() + curr.size() - 1); //erase the result of the last operation you tried
                }
            }
        }
        return false;
    }
};
