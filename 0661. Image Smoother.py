class Solution:
    def imageSmoother(self, grid: List[List[int]]) -> List[List[int]]:
        N, M = len(grid), len(grid[0])
        dirs = ((0,1), (0,-1), (1,0), (-1,0), (1,1), (1,-1), (-1,1), (-1,-1))
        res = [ [0] * M for i in range(N)]
        
        def out(i: int, j: int):
            return i >= N or i == -1 or j >= M or j == -1
        
        for i in range(N):
            for j in range(M):
                count = 1
                total = grid[i][j]
                for d in dirs:
                    ni, nj = i + d[0], j + d[1]
                    if out(ni,nj):
                        continue
                    count += 1
                    total += grid[ni][nj]
                res[i][j] = int(total/count)
        return res
