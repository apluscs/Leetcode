class Solution:
    def superPow(self, a: int, b: List[int]) -> int:
        N = len(b)
        if N == 0:
            return 1
        last = b[N-1]
        b = b[:-1]  # cut off last digit
        return (self.modPow(a,last) * self.modPow(self.superPow(a,b), 10)) % 1337
        
    def modPow(self, a: int, b: int) -> int:
        res = 1
        for i in range(b):
            res = (res * a) % 1337
        return res
