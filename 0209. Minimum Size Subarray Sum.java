class Solution {  //O(n) solution
    public int minSubArrayLen(int K, int[] nums) {
        int i = 0, j = 0, sum = 0, res = Integer.MAX_VALUE, N = nums.length;
        while (j != N) {
            while (j != N && sum < K) sum += nums[j++]; //reach as far right as needed
            while (i != N && sum >= K) {
                res = Math.min(res, j - i); //consider all valid windows
                sum -= nums[i++]; //bump out whatever isn't needed
            }
        }
        if (res != Integer.MAX_VALUE) return res; //found valid solution
        return 0;
    }
}
