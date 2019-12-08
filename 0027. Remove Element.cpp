class Solution {
    public:
        int removeElement(vector < int > & nums, int val) {
            int ind = 0, N = nums.size();
            for (int i = 0; i != N; i++) //nums[ind] is filled in with non-val nums
                if (nums[i] != val) nums[ind++] = nums[i];
            return ind;
        }
};
