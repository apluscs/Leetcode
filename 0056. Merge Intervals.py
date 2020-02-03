class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        res = []
        if len(intervals) == 0:
            return res
        intervals.sort(key = lambda iv : iv[0]) # by starting time; reasoning is that the "earliest" starting interval must belong to a group, 
        # we need to extend this group as far as it can go
        start = intervals[0][0]
        end = intervals[0][1]
        for iv in intervals:
            if iv[0] <= end:    # we can continue this chain
                end = max(end, iv[1])
            else:   # start a new chain
                res.append([start,end])
                start = iv[0]   
                end = iv[1]
        res.append([start,end])
        return res
