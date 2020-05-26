class Solution:
    def distributeCandies(self, candies: int, N: int) -> List[int]:
        res = [0] * N
        curr, i = 1, 0
        while candies > 0:
            res[i] += curr
            candies -= curr
            if candies < 0: # gave res[i] too much
                res[i] += candies
            curr += 1
            i = (i + 1) % N
        return res
