class CustomStack:
    nums = []
    maxSize = 0
    i = 0
    def __init__(self, maxSize: int):
        self.nums = [0] * maxSize
        self.maxSize = maxSize

    def push(self, x: int) -> None:
        if self.i == self.maxSize:
            return
        self.nums[self.i] = x
        self.i += 1

    def pop(self) -> int:
        if self.i == 0:
            return -1
        self.i -= 1
        return self.nums[self.i]

    def increment(self, k: int, val: int) -> None:
        for j in range(min(self.i, k)):
            self.nums[j] += val


# Your CustomStack object will be instantiated and called as such:
# obj = CustomStack(maxSize)
# obj.push(x)
# param_2 = obj.pop()
# obj.increment(k,val)
