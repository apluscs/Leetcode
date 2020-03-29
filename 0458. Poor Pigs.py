class Solution:
    def poorPigs(self, N: int, minutesToDie: int, minutesToTest: int) -> int:
        cycles = int(minutesToTest/minutesToDie)
        return int(ceil(log(N)/log(cycles + 1)))
    # max number of buckets able to be tested = (#cycles + 1) ^ pigs
