class Solution:
    
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        ev = 0
        od = 0
        evens = [0] * int(len(nums)/2)  # half the size of nums
        odds  = [0] * int(len(nums)/2) 
        for num in nums:
            if (num % 2) == 0:  # even num found
                evens[ev] = num
                ev += 1
            else:
                odds[od] = num
                od += 1
        for i in range(0, len(nums), 2):
            nums[i] = evens[ int(i/2) ] # divide by 2 to get index in evens array
            nums[i+1] = odds[ int(i/2) ]    # odd follows even
        return nums
        
