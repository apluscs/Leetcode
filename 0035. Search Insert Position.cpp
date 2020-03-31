class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;    // low should end up at first pos whose elem is >= target
        while(low <= high){
            int mid = int(( long(low) + high) / 2);
            if(nums[mid] < target)
                low = mid + 1;
            else high = mid - 1;
        }
        return low;
    }
};
