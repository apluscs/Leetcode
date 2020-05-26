class Solution:
    def sampleStats(self, count: List[int]) -> List[float]:
        bottom = sys.maxsize
        top = -bottom - 1
        mean = 0
        total = 0
        mode = 0
        median = 0
        for i in range(len(count)):
            if count[i] != 0:
                top = i
                bottom = min(i, bottom)
            mean += count[i] * i
            total += count[i]
            mode = mode if count[mode] > count[i] else i
        half_total = int(total/2) + 1   # exactly the right index for odd-totaled nums
        if total % 2 == 0:
            for i in range(len(count)):
                if half_total == 1: # means this is the upper number in the "median pair"
                    median = (i + i - 1)/2  # average with lower number (i-1)
                    break
                if half_total <= count[i]:  # half total > 1
                    median = i
                    break
                half_total -= count[i]
        
        if total % 2 == 1:
            for i in range(len(count)):
                if half_total <= count[i]:  # found the middle number
                    median = i
                    break
                half_total -= count[i]
                
        return [bottom, top, mean/total, median, mode]
