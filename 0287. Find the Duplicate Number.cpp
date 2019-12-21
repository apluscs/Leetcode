class Solution {
    public:
        int findDuplicate(vector < int > & nums) {
            sort(nums.begin(), nums.end()); //nlogn
            int N = nums.size();
            for (int i = 0; i != N - 1; i++)
                if (nums[i] == nums[i + 1]) return nums[i]; //duplicate found
            return -1;
        }
};
