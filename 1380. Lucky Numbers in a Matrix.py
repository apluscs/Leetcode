class Solution:
    def luckyNumbers (self, matrix: List[List[int]]) -> List[int]:
        N, M = len(matrix), len(matrix[0])
        rows, cols, res = [0] * N, [0] * M, []
        for i in range(N):
            bottom = matrix[i][0]
            for j in range(M):
                bottom = min(bottom, matrix[i][j])
            rows[i] = bottom
        
        for j in range(M):
            top = matrix[0][j]
            for i in range(N):
                top = max(top, matrix[i][j])
            cols[j] = top
            
        for i in range(N):
            for j in range(M):
                if(matrix[i][j] == rows[i] and matrix[i][j] == cols[j]):
                    res.append(matrix[i][j])
        return res
