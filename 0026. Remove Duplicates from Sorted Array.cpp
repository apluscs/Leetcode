class Solution {
    public:
        int removeDuplicates(vector < int > & nums) {
            int N = nums.size(), ind = 0, i = 1;
            if (N == 0) return 0;
            while (true) {
                while (i != N && nums[i] == nums[ind]) i++; //nums[ind] is uniq, jump over all repeats of it
                if (i == N) break; //next line is error-prone
                nums[++ind] = nums[i++];
            }
            return ind + 1; //convert to base-1
        }
};
