class Solution { //very similar to 3Sum
    public static int N;
    public static int[] nums;
    public int threeSumClosest(int[] numbs, int target) {
        nums = numbs;
        N = nums.length;
        int res = 0, diff = Integer.MAX_VALUE;
        Arrays.sort(nums);
        for (int i = 0; i < N - 2; i++) {
            if (i > 0 && nums[i - 1] == nums[i]) continue; //each target is unique
            int sum = nums[i] + twoSum(i + 1, N - 1, target - nums[i]);
            if (Math.abs(sum - target) < diff) {
                diff = Math.abs(sum - target);
                res = sum;
            }
        }
        return res;
    }
    public int twoSum(int start, int end, int target) {
        int res = 0, diff = Integer.MAX_VALUE;
        while (start < end) {
            int sum = nums[start] + nums[end];
            if (Math.abs(sum - target) < diff) {
                diff = Math.abs(sum - target);
                res = sum;
            }
            if (sum == target) return target;
            else if (sum > target) {
                end--; //skip over duplicates = much faster runtime
                while (start < end && (end == N - 1 || nums[end + 1] == nums[end])) end--;
            } else {
                start++; //skip over duplicates
                while (start < end && nums[start - 1] == nums[start]) start++;
            }
        }
        return res;
    }
}
