class Solution:
    def myPow(self, x: float, n: int) -> float:
        if n == 0:  
            return 1
        if n < 0:   # just 1/x^(positive n)
            return 1/self.myPow(x, -n)
        res = self.myPow(x, int(n/2))
        return res * res * x if n % 2 == 1 else res * res 
