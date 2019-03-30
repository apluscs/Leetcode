class Solution {
    public int[] twoSum(int[] nums, int target) {
        HashMap<Integer,Integer> map=new HashMap<>();   //value, index
        for(int i=nums.length-1;i!=-1;i--){
            if(map.containsKey(target-nums[i])) //have we seen matching complement?
                return new int[] {i,map.get(target-nums[i])};
            map.put(nums[i],i);
        }
        return new int[1];  //NEVER used
    }
}
