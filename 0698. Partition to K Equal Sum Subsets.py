class Solution:

# shoutout to Andy Jiang
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        sum_total=sum(nums)
        nums=sorted(nums,reverse=True)  # highest at front
        if sum_total%k != 0:    # cannot split into k boxes
            return False
        size_each=sum_total/k
        size_left=[size_each for i in range(k)]
        box_numbers=[0] # [i] = box nums[i] is in
        n=len(nums)
        if n == 1:
            return True
        while True:
            cur=len(box_numbers)-1  # current num
            if size_left[box_numbers[cur]]<nums[cur]:    # cannot fit into current box
                box_numbers[cur]+=1 # try next box
                while box_numbers[-1]>=k:   # invalid boxes
                    if len(box_numbers) <= 2:   
                        return False
                    box_numbers.pop(-1) # pop out last added num 
                    cur-=1  
                    size_left[box_numbers[cur]]+=nums[cur]
                    box_numbers[-1] +=1 # try next box
            else:
                if len(box_numbers) == n:
                    return True
                size_left[box_numbers[-1]]-=nums[cur]   # add cur to this box
                box_numbers.append(0)
        return True
        
