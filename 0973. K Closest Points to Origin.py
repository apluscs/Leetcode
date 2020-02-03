class Solution: # so much faster and more elegant
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        return heapq.nsmallest(K, points, lambda p: p[0] * p[0] + p[1] * p[1])

class Element:
    def __init__(self, x, y):
        self.dist = x*x + y*y
        
    def __lt__(self, other):    # farthest will be popped first
        return self.dist > other.dist
    
    def __eq__(self, other):    # another function you need to fill in I guess
        return self.dist == other.dist

class SolutionSLOW:
    def kClosest(self, points: List[List[int]], K: int) -> List[List[int]]:
        freqs = []
        for point in points:
            heapq.heappush(freqs, (Element(point[0], point[1]), point)) # tuple, first is just used for ordering
            if len(freqs) > K:  # beyond closest k elements
                heapq.heappop(freqs)
        res = [ [] for i in range(len(freqs)) ]     #      
        for i in range(len(res)-1,-1,-1):   # just practicing backwards iteration
            res[i] = heapq.heappop(freqs)[1]
        # print(len(res))
        return res
