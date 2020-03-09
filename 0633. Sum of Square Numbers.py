import math  
class Solution:
    def judgeSquareSum(self, N: int) -> bool:
        for i in range(int(N/2) + 1):
            a = i * i
            b = int(math.sqrt(N - a))
            if a + b * b == N:
                return True
            if a > b * b:   # don't check duplicate pairs, also prevents a from getting > N
                return False
            i += 1
        return False
            
            
            
