class Solution {
    public boolean canPlaceFlowers(int[] nums, int n) {
        int res = 0, N = nums.length;
        for (int i = 0; i != N; i++) {
            if (nums[i] == 0 && (i == 0 || nums[i - 1] == 0) && (i == N - 1 || nums[i + 1] == 0)) {
                res++;
                nums[i] = 1;
            }
            if (res >= n) return true;
        }
        return false;
    }
}
