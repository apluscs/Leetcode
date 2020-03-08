class Solution:
    def rob(self, nums: List[int]) -> int:
        N = len(nums)
        if N == 0:
            return 0
        if N == 1:
            return nums[0]
        p2, p1 = nums[0], max(nums[0], nums[1]) # 2 days before, 1 day before
        for i in range(2, N):
            curr = max(nums[i] + p2, p1)
            p2 = p1
            p1 = curr   # update for next day
        return p1
