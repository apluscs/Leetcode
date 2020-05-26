class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort(reverse = True)
        for i in range(len(nums)-2):
             if nums[i+1] + nums[i+2] > nums[i]:    # two smallers can dominate the largest
                return nums[i+1] + nums[i+2] + nums[i]
        return 0
