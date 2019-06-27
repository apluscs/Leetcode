class Solution {
    public int numSubarrayBoundedMax(int[] A, int L, int R) {
        int left = -1, right = -1, res = 0; //left=oldest invalid elem that is too big (ruins the subarray)
        //right=newest elem within these bounds (anchors the subarray)
        for (int i = 0; i != N; i++) {
            if (nums[i] > R) left = i;
            if (nums[i] >= L) right = i; //if nums[i] doesn't break R, extend the subarray to include it
            res += right - left; //adds all subarrays with i as its rightmost point and left+1, left+2...right as leftmost point
        }
        return res;
    }
}
