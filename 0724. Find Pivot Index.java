class Solution {
    public int pivotIndex(int[] nums) {
        int sum = 0;
        if (nums.length == 0) return -1;
        if (nums.length == 1) return 0;
        int[] sums = new int[nums.length + 1]; //cummulative sum, shifted over 1 for an initial sum of 0
        for (int i = 0; i != nums.length; i++) {
            sum += nums[i];
            sums[i + 1] = sum;
        }
        for (int i = 1; i != nums.length + 1; i++) { //sum[left]==total sum-sum[here]?
            if (sums[i - 1] == sums[nums.length] - sums[i]) return i - 1;
        }
        return -1;
    }
}
