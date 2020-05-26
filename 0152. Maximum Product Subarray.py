class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        res, N, largest, smallest = nums[0], len(nums), 1, 1   # curr becomes max product subarray ending at index i
        for num in nums:
            if(num < 0):    # swap large and small, treat num as a positive now
                temp = largest
                largest = smallest
                smallest = temp
            largest = max(num, largest * num)   # need to have num as an option in case we want to start anew (ex. largest is -2 and num is 6, 6 > -12)
            smallest = min(num, smallest * num) # need to keep this in case we see multiple negatives
            res = max(res, largest)
        return res
