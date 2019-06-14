class Solution {
    public boolean isIdealPermutation(int[] nums) {
        int N = nums.length;
        for (int i = 0; i != N; i++)
            if (Math.abs(nums[i] - i) > 1) return false;
        //deviates more than 2 from expected position? 
        //ex. 1,2,0 - the two nums larger than 0 are pushed left, but only one can be local; the other must be local and global
        //ex. 2,1,0 - the two nums smaller than 2 are moved right, but one will be too far away to be only local
        return true;
    }
}
