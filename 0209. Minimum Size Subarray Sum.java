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

class Solution2 {   //O(nlogn) solution
    public int minSubArrayLen(int K, int[] nums) {
        int low = 1, high = nums.length;
        int res = Integer.MAX_VALUE;
        while (low <= high) {   //bin search
            int mid = (low + high) / 2;
            if (able(K, nums, mid)) {   
                high = mid - 1;
                res = Math.min(res, mid);
            } else low = mid + 1;
        }
        if (res == Integer.MAX_VALUE) return 0;
        return res;
    }
    public boolean able(int K, int[] nums, int len) {   //can you find a subarray of this length that will meet K?
        int i = 0, j = 0, sum = 0;
        while (j < len) sum += nums[j++];
        while (j != nums.length) {
            if (sum >= K) return true;
            sum += nums[j++] - nums[i++];
        }
        if (sum >= K) return true;
        return false;
    }
}
