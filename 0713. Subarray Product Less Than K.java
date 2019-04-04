class Solution {
    public int numSubarrayProductLessThanK(int[] nums, int k) {
        if (k <= 1) return 0; //no way to make 0 or -prod with pos numbers
        int N = nums.length, l = 0, res = 0, prod = 1;
        for (int r = 0; r != N; r++) { //keep expanding right until you need to kick out left side
            prod *= nums[r];
            while (prod >= k) prod /= nums[l++];
            res += r - l + 1; //all subarrays of expanding length starting from r ([r],[r,r-1],[r,r-1,r-2],etc)
        }
        return res;
    }
}
