class Solution:
    def rob(self, nums: List[int]) -> int:
        N = len(nums)
        if N == 0:
            return 0
        if N == 1:
            return nums[0]
        p2, p1 = nums[0], max(nums[0], nums[1]) # 2 days before, 1 day before
        for i in range(2, N-1): # option 1 = 0 thru N-1
            curr = max(nums[i] + p2, p1)
            p2 = p1
            p1 = curr   # update for next day
        res = p1
        if N == 2:
            return p1
        p2, p1 = nums[1], max(nums[1], nums[2])
        for i in range(3, N):   # option 2 = 1 thru N, because we cannot do houses 0 AND N-1 now
            curr = max(nums[i] + p2, p1)
            p2 = p1
            p1 = curr   # update for next day
        return max(p1, res)
