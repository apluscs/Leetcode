class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        N = len(nums)
        res, curr = [0] * N, 1
        res[0] = nums[0]    # make it a cummulative product array
        for i in range(1, N):
            res[i] = nums[i] * res[i-1]
            
        for i in range(N-1, 0, -1): # go backwards
            res[i] = res[i-1] * curr    # curr = everything to the right of i, res[i-1] = everything to the left of i
            curr *= nums[i] # update curr
        res[0] = curr       # bounds issues
        return res
        
