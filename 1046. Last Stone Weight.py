
class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        heap= []
        for i in range(len(stones)):
            stones[i] = -stones[i]  # make all negative so largest magnitude is at the front
        heapq.heapify(stones)   # make stones a priority queue
        while stones:
            a = heapq.heappop(stones)
            if len(stones) == 0:    # last element left
                return -a
            b = heapq.heappop(stones)   #"smaller"than a
            if a != b:  
                heapq.heappush(stones, a-b) # a-b is negative
        return 0
