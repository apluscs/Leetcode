class Solution:
    def minMoves(self, nums: List[int]) -> int:
        bottom = sys.maxsize
        res = 0
        for num in nums:
            bottom = min(bottom, num)
            res += num
        return res - bottom * len(nums)
    
    # answer = summation of each (value - min of entire array)
    # because incrementing the lowest N-1 elements helps you get to the same goal (uniform array) as decrementing the highest element
