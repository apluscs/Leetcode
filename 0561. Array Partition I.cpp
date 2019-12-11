class Solution {
    public:
        int arrayPairSum(vector < int > & nums) {
            sort(nums.begin(), nums.end()); //pair all small nums with each other
            int res = 0;
            for (int i = nums.size() - 1; i != -1; i -= 2) {
                res += min(nums[i], nums[i - 1]); //take min of each pair  
            }
            return res;
        }
};
