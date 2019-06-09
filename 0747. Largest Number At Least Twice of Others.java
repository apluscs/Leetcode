class Solution {
    public int dominantIndex(int[] nums) {
        int N = nums.length;
        if (N == 1) return 0; //only num available
        int max1 = -1, max2 = -1, ind = -1;	//ind = index of largest num
        for (int i = 0; i != N; i++) {
            if (nums[i] > max1) {
                max2 = max1;
                max1 = nums[i];
                ind = i;
            } else if (nums[i] > max2) max2 = nums[i];
            // System.out.println(max1 + ", " + max2);
        }

        if (max1 >= max2 * 2) return ind;
        return -1;
    }
}
