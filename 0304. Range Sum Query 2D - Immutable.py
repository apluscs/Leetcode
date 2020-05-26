class NumMatrix:
    sums = [[]]
    def __init__(self, matrix: List[List[int]]):
        self.sums = matrix
        if len(matrix) == 0:
            return
        for j in range(1, len(matrix[0])):  # first row
            self.sums[0][j] += self.sums[0][j-1]
        for i in range(1, len(matrix)):
            self.sums[i][0] += self.sums[i-1][0]    # first column
            for j in range(1, len(matrix[0])):
                self.sums[i][j] += self.sums[i-1][j] + self.sums[i][j-1] - self.sums[i-1][j-1]  # need to subtract the box you added twice

    def sumRegion(self, row1: int, col1: int, row2: int, col2: int) -> int:
        res = self.sums[row2][col2]
        res -= 0 if row1 == 0 else self.sums[row1-1][col2]
        res -= 0 if col1 == 0 else self.sums[row2][col1-1]
        if row1 != 0 and col1 != 0:
            res += self.sums[row1-1][col1-1]    # add the box you subtracted twice
        return res

# Your NumMatrix object will be instantiated and called as such:
# obj = NumMatrix(matrix)
# param_1 = obj.sumRegion(row1,col1,row2,col2)
