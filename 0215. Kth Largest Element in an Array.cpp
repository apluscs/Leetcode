class Solution {
    public:
        int findKthLargest(vector < int > & nums, int k) {
            int head = 0, tail = nums.size() - 1, pivot, i, j;
            while (true) {
                i = head;
                j = tail;
                pivot = nums[i++];
                while (i <= j) {
                    if (nums[i] >= pivot) i++;
                    else if (nums[j] < pivot) j--;
                    else swap(nums, i++, j--);
                }
                int first = i - head; //length of first half
                if (first == k) return pivot; //elem at end of first half(theoretically, pivot)
                if (first < k) {
                    k -= first; //search in elems lower than pivot
                    head = i;
                } else {
                    tail = i - 1; //i will always be one index larger than last index of first half
                    head++;
                }
            }
        }

    void swap(vector < int > & nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
};
