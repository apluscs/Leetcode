class NumArray:
    sums = []
    def __init__(self, nums: List[int]):
        self.sums = nums    #refer to same list
        for i in range(1,len(nums)):
            self.sums[i] = self.sums[i-1] + nums[i] # cummulative sum

    def sumRange(self, i: int, j: int) -> int:
        return self.sums[j] - (0 if i == 0 else self.sums[i-1])


# Your NumArray object will be instantiated and called as such:
# obj = NumArray(nums)
# param_1 = obj.sumRange(i,j)
