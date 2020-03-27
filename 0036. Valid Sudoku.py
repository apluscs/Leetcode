class Solution:
    # could be much faster with hashing what you've seen before
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        def bad(i: int, j: int) -> bool:
            if board[i][j] == '.':  # a dot is never bad
                return False
            for k in range(9):
                if board[i][k] == board[i][j] and k != j or board[k][j] == board[i][j] and k != i:  # check that coordinates aren't the exact same
                    return True
            si, sj = int(i/3) * 3, int(j/3) * 3 # top left corner of box
            for k in range(3):
                for l in range(3):
                    if board[si + k][sj + l] == board[i][j] and (si + k != i or sj + l != j):
                        return True
            return False
        
        for i in range(9):
            for j in range(9):
                if bad(i, j):
                    return False
        return True
