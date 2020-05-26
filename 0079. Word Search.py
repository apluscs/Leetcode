class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        dirs = ((0,1), (0,-1), (1,0), (-1,0))
        N, M = len(board), len(board[0])
        path = set()
        
        def dfs(i: int, j: int, k: int) -> bool:
            if k == len(word):
                return True
            if (i,j) in path or i == -1 or j == -1 or i == N or j == M or word[k] != board[i][j]:
                return False
            path.add((i,j))
            for d in dirs:
                if dfs(i + d[0], j + d[1], k + 1):
                    return True
            path.remove((i,j))    # (i,j) was not a valid path, remove it to try something else     
            return False
        
        for i in range(N):
            for j in range(M):
                path = set()    # clear it out everytime
                if dfs(i, j, 0):    # try every cell as starting cell
                    return True
        return False
