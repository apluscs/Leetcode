class Solution:
    def minMoves2(self, nums: List[int]) -> int:
        mid = int(len(nums)/2)
        left = 0
        right = len(nums) - 1
        pivot = -1
        while pivot != mid:
            pivot = self.median(nums, left, right)
            if pivot > mid:
                right = pivot - 1
            else:
                left = pivot + 1
        res = 0
        for num in nums:
            res += abs(num - nums[mid]) # nums[mid] is the 'upper' median of nums
        return res
    
    def median(self, nums: List[int], left: int, right: int) -> int:
        pivot = right
        while True:
            while nums[left] < nums[pivot]: # not <= bc we don't want left to be too big
                left += 1
            while left < right and nums[right-1] >= nums[pivot]:
                right -= 1
            if left >= right:
                break
            self.swap(nums, left, right-1)
        self.swap(nums, pivot, left)
        return left
    
    def swap(self, nums: List[int], a: int, b: int):
        temp = nums[a]
        nums[a] = nums[b]
        nums[b] = temp
        
        
        
