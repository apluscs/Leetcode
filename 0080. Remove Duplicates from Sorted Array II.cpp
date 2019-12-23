class Solution {
    public:
        int removeDuplicates(vector < int > & nums) {
            int ind = 0, i = 0, N = nums.size();
            if (N < 3) return N; //no work needed
            for (; i < N - 1; i++) {
                nums[ind++] = nums[i]; //nums[i] has never been seen before
                if (nums[i + 1] == nums[i]) nums[ind++] = nums[i + 1]; //at most 2 allowed
                while (i < N - 1 && nums[i + 1] == nums[i]) i++; //advance i to last of repeated num in chain,
            } //so next iteration i starts on a new num
            if (i < N && nums[N - 1] != nums[N - 3]) nums[ind++] = nums[N - 1]; 
            //still more to process in nums? last num is not >= third in chain?
            return ind;
        }
};
