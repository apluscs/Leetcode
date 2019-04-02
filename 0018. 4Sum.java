class Solution {

    public static int N;
    public static int[] nums;
    public static List < List < Integer >> res;
    public List < List < Integer >> fourSum(int[] numbs, int target) {
        res = new ArrayList < > ();
        nums = numbs;
        N = nums.length;
        Arrays.sort(nums);
        for (int i = 0; i < N - 2; i++) {
            if (i != 0 && nums[i - 1] == nums[i]) continue; //each target is unique
            threeSum(i + 1, N - 1, target - nums[i], nums[i]); //quadruple will always ascend
        }
        return res;
    }

    public void threeSum(int start, int end, int target, int a) {
        for (int i = start; i < end - 1; i++) { //any further = can't make triple
            if (i != start && nums[i - 1] == nums[i]) continue; //everything prior shouldn't be considered for triple (why i != start)
            twoSum(i + 1, N - 1, target - nums[i], a, nums[i]); //triple will always ascend
        }
    }

    public void twoSum(int start, int end, int target, int a, int b) { //literally copy-pasted from 3Sum
        while (start < end) {
            if (nums[start] + nums[end] == target) {
                res.add(Arrays.asList(a, b, nums[start], nums[end]));
                start++; //try a new triple
                end--; //end+1 is never out of bounds
                while (start < end && nums[start - 1] == nums[start]) start++;
                while (start < end && nums[end] == nums[end + 1]) end--;
            } else if (nums[start] + nums[end] > target) end--; //sum is too large
            else start++; //sum is too small
        }
    }
}
