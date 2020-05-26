class Solution:
    dir = ((1,0), (-1,0), (0,1), (0,-1), (1,-1), (1,1), (-1,1), (-1,-1))
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        res = 1
        que = collections.deque()
        vis = set()
        N = len(grid)
        que.appendleft((0,0))
        
        while len(que) != 0:
            size = len(que)
            for i in range (0,size):
                curr = que.pop()
                i = curr[0]
                j = curr[1]
                if i == -1 or i == N or j == -1 or j == N or curr in vis or grid[i][j] == 1:    # out of range or visited or blocked
                    continue
                vis.add(curr)
                if i == N-1 and j == N-1:   # target found
                    return res
                for d in self.dir:
                    ni = i + d[0]
                    nj = j + d[1]
                    que.appendleft((ni, nj))
            res += 1
        return -1    
    
    
    
