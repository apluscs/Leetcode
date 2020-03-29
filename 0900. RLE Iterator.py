class RLEIterator:

    def __init__(self, A: List[int]):
        self.nums = A
        self.i = 0

    def next(self, N: int) -> int:
        while self.i != len(self.nums) and N > self.nums[self.i]:
            N -= self.nums[self.i]  # this much less we need to traverse
            self.i += 2 # jump to next pair
        if self.i == len(self.nums):    # ran out
            return -1
        self.nums[self.i] -= N  
        return self.nums[self.i+1]


# Your RLEIterator object will be instantiated and called as such:
# obj = RLEIterator(A)
# param_1 = obj.next(n)
