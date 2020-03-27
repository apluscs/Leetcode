class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        frq, N = {}, len(nums)/2
        for num in nums:
            if num not in frq:
                frq[num] = 0
            frq[num] += 1
            if frq[num] == N:
                return num
        return -1
