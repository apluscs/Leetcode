class Solution {
  public:
    void sortColors(vector < int > & nums) {
      int z_ind = 0, t_ind = nums.size() - 1;
      for (int i = 0; i <= t_ind; ++i) { // no need to reach "2 territory"
        if (nums[i] == 0) swap(nums, i, z_ind++); // move the 0 to the next available spot on the left
        else if (nums[i] == 2) swap(nums, i--, t_ind--); // i doesn't change this time, in case the new element at pos i is a 0 (don't wanna skip that!)
      }

    }

  void swap(vector < int > & nums, int a, int b) {
    int temp = nums[a];
    nums[a] = nums[b];
    nums[b] = temp;
  }
};
