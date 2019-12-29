class Solution {
    public:

        bool canReach(vector < int > & nums, int start) {
            return helper(nums, start);
        }

    bool helper(vector < int > & arr, int i) {
        if (i < 0 || i >= arr.size() || arr[i] == -1) return false; // out or visited
        if (arr[i] == 0) return true; // found it
        int temp = arr[i];
        arr[i] = -1; // mark as visited
        return helper(arr, i + temp) || helper(arr, i - temp); // try both options
    }
};
