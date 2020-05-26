class Solution:
    def divide(self, N: int, divisor: int) -> int:
        res, shifts, bad = 0, 0, (1 << 31) - 1
        neg = divisor < 0 and N > 0 or divisor > 0 and N < 0
        if N == -bad - 1 and divisor == -1:   # N is INT_MIN, divisor is -1
            return bad
        divisor = abs(divisor)
        N = abs(N)
        
        while N >= divisor:
            shifts, num = 0, divisor
            while num <= N:
                num <<= 1
                shifts += 1
            N -= (num >> 1) # shifted it left one too many
            res += 1 << (shifts - 1)
        return -res if neg else res
            
            
