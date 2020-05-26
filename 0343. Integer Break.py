class Solution:
    def integerBreak(self, N: int) -> int:
        if N < 4:
            return N - 1    # easy way to summarize trivial cases
        a = int(pow(3, int(N/3)))
        if N % 3 == 0:  # can make with all 3's
            return a
        if N % 3 == 1:  # remove one 3, replace w 2 * 2
            return int(a/3 * 4)
        return int(a * 2)   # 2 left over, use it 
        
        # optimal solution is to use with mostly 3's and sometimes 2's (anything higher can be broken down into better subcomponents)
        # 4 --> 2 * 2
        # 5 --> 3 * 2, not 4 * 1
        # 6 --> 3 *3, not 4 * 2 or 5 * 1
