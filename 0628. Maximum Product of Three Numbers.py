class Solution:
    def maximumProduct(self, nums: List[int]) -> int:
        top1, top2, top3, bot1, bot2 = float('-Inf'),float('-Inf'),float('-Inf'),float('Inf'),float('Inf')  
        for num in nums:    # will change to greatest 3 nums and lowets 2 nums
            if num >= top1:
                top1, top2, top3 = num, top1, top2
            elif num >= top2:
                top2, top3 = num, top2
            elif num >= top3:
                top3 = num
            if num <= bot1:
                bot1, bot2 = num, bot1
            elif num <= bot2:
                bot2 = num
            
        return max(top1 * top2 * top3, top1 * bot1 * bot2)
