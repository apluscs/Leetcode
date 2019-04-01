class Solution {
    public int maxArea(int[] nums) {
        int i=0,j=nums.length-1,res=0;
        while(i!=j){    //try each possible width
            int temp=(j-i)*Math.min(nums[i],nums[j]);   //shorter line determines height
            res=Math.max(res,temp);
            if(nums[i]<nums[j]) i++;    //try to increase shorter plank
            else j--;   //shifting the other index won't increase area at all
        }
        return res;
    }
}
