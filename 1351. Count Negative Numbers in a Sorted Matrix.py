class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        N, M, res = len(grid), len(grid[0]), 0
        for i in range(N):
            for j in range(M):
                if grid[i][j] < 0:
                    res += 1
        return res
