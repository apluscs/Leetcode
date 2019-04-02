class Solution {
    public static int N;
    public static int[] nums;
    public List < List < Integer >> threeSum(int[] numbs) {
        nums = numbs;
        N = nums.length;
        List < List < Integer >> res = new ArrayList < > ();
        Arrays.sort(nums);
        for (int i = 0; i < N - 2; i++) {
            if(nums[i]>0) break;    //no way to make 0 with all positives
            if (i > 0 && nums[i - 1] == nums[i]) continue;  //each target is unique
            twoSum(i + 1, N - 1, -nums[i], res);    //triple will always ascend
        }
        return res;
    }

    public void twoSum(int start, int end, int target, List < List < Integer >> res) {
        while (start < end) {
            if (nums[start] + nums[end] == target) {
                res.add(Arrays.asList(-target, nums[start], nums[end]));
                start++;    //try a new triple
                end--; //end+1 is never out of bounds
                while (start < end && nums[start - 1] == nums[start]) start++;
                while (start < end && nums[end] == nums[end + 1]) end--;
            } else if (nums[start] + nums[end] > target) end--; //sum is too large
            else start++;   //sum is too small
        }
    }
}
