class Solution: # O(N^2) takes too long
    def containsNearbyDuplicate(self, nums: List[int], k: int) -> bool:
        prev = {}
        for i in range(len(nums)):
            if nums[i] in prev and i - prev[nums[i]] <= k:  #last seen index of nums[i] is close enough to i
                return True
            prev[nums[i]] = i   # update last seen index
            
        return False
