class Solution {
    public int maxChunksToSorted(int[] nums) { //very similar to Partition Lables (763)
        int res = 0, end = 0, ind = 0, N = nums.length; //method is to keep intervals that must be together together
        while (ind != N) {  //intervals are creaetd by the index and where the nums[index] needs to be, which is essentially given by nums[index]
            while (ind <= end) {
                end = Math.max(end, nums[ind]); //extend end if you need to
                ind++;
            }
            res++;
            if (ind != N) end = nums[ind];
        }
        return res;
    }
}
