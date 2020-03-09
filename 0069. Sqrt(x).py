class Solution:
    def mySqrt(self, x: int) -> int:
        i = 0
        while True:
            sq = i * i
            if sq == x: 
                return i
            if sq > x:  # truncate, so go to the one below
                return i - 1
            i += 1
        return i
