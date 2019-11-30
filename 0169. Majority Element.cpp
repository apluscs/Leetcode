class Solution {
    public:
        int majorityElement(vector < int > & nums) {
            int cand = nums[0], count = 1;
            for (int i = nums.size() - 1; i != 0; i--) {
                if (count == 0) cand = nums[i];
                if (nums[i] == cand) count++;
                else count--;
            }
            return cand;
        }
};
