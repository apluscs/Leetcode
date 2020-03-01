class Solution:
    def xorGame(self, nums: List[int]) -> bool:
        xor = 0
        for num in nums:
            xor ^= num
        return xor == 0 or len(nums) % 2 == 0
    
    # if #elems is even and cummulative xor != 0, that means Alice just has to avoid picking a number that == cummulative_xor 
    # (doing so would leave the remainder of the xor == 0 --> Bob wins); eventually, Bob will pick the last num --> Alice wins
