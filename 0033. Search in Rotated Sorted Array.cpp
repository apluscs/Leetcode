class Solution {
    public:
        int search(vector < int > & nums, int target) {
            int N = nums.size(), low = 0, high = N - 1;
            if (N == 0) return -1;
            while (low < high) { // after this low = high = index of lowest num (pivot index)
                int mid = (low + high) >> 1;
                if (nums[mid] > nums[high]) low = mid + 1;
                else high = mid;
            } // choose which section of nums to binary search on
            int res = target > nums[N - 1] ? bSearch(nums, target, 0, low - 1) : bSearch(nums, target, low, N - 1);
            return nums[res] == target ? res : -1; // check if it's in nums
        }

    int bSearch(vector < int > & nums, int target, int low, int high) {
        while (low <= high) {
            int mid = (low + high) >> 1;
            if (nums[mid] == target) return mid;
            if (nums[mid] > target) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};
