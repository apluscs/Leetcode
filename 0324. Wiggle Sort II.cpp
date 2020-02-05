class Solution {
  public:
    void wiggleSort(vector < int > & nums) {
      int N = nums.size(), low = 0, high = N - 1;
      if (N < 2) return;
      vector < int > ::iterator m = nums.begin() + (N + 1) / 2;
      nth_element(nums.begin(), m, nums.end()); // this is O(N) !!
      int med = * m;
      for (int i = 0; i <= high; ++i) {
        if (nums[wig_num(nums, i)] > med) { // push all top half elements to the left side starting at index 1 incrementing by 2
          swap(nums, wig_num(nums, low++), wig_num(nums, i));
        } else if (nums[wig_num(nums, i)] < med) { // bottom half goes to the right hand side starting at index N-1 decrementing by 2
          swap(nums, wig_num(nums, high--), wig_num(nums, i--));
        } // this way, orignal middle elements are spread as far appart from each other (mid + 1 goes all the way to 0, mid - 1 goes all the to N-1)
      }
      // 3 way partitioninig with wigged indexes
    }

  int wig_num(vector < int > & nums, int ind) {
    int N = nums.size(); //
    return (1 + 2 * ind) % (N | 1); // some math I don't completely understand, in real interview I would make this simpler
  }

  void swap(vector < int > & nums, int a, int b) {
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
  }
};
