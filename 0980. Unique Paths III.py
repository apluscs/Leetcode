class Solution:
    def uniquePathsIII(self, grid: List[List[int]]) -> int:
        totz, si, sj, N, M, res = 0, -1, -1, len(grid), len(grid[0]), 0
        for i in range(N):
            for j in range(M):
                if grid[i][j] == 0:
                    totz += 1 # count how many zeros
                    res = 0
                elif grid[i][j] == 1:
                    si, sj = i, j
        dirs = ((0,1), (0,-1), (1,0), (-1,0))
        path = set()
        def dfs(i: int, j: int) -> None:
            nonlocal res    # not global, since global is outside of class Solution
            if i == -1 or j == -1 or i == N or j == M or (i,j) in path or grid[i][j] == -1:
                return
            if grid[i][j] == 2 and len(path) - 1 == totz:   # minus initial 1
                res += 1    # hit every zero
                return
            path.add((i,j)) # could be faster by just changing this to -1, counting #zeroes you stepped on as you go
            for d in dirs:
                dfs(i + d[0], j + d[1])
            path.remove((i,j))
            
        dfs(si, sj) # try every path basically
        return res
    
    
    
