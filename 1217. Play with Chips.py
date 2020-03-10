class Solution:
    def minCostToMoveChips(self, chips: List[int]) -> int:
        odds, evens = 0, 0
        for num in chips:
            if num % 2 == 0:
                evens += 1
            else:
                odds += 1
        return min(evens, odds)
    
# either move all odd chips to an even pos, or all even chips to an odd pos (moving odd to odd or even to even = no cost)
