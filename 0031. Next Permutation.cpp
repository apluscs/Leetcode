class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        for(int i = nums.size() - 1; i > 0; --i){
            if(nums[i - 1] < nums[i]){
                int j = nums.size() - 1;
                while(nums[j] <= nums[i - 1]) j--;
                swap(nums[i-1], nums[j]);   // nums[j] = rightmost number > nums[i-1]
                reverse(nums.begin() + i, nums.end());  // now this post-chunk is in ascending order, to minimize it just reverse it
                return;
            }
        }
        reverse(nums.begin(), nums.end());  // non-increasing order to begin with
    }
};
