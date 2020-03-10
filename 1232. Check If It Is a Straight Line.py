class Solution:
    def checkStraightLine(self, coors: List[List[int]]) -> bool:
        N = len(coors)
        if coors[1][0] == coors[0][0]:  # vertical line at this x coordinate
            for i in range(N):
                if coors[i][0] != coors[0][0]:
                    return False
            return True
        m = (coors[1][1] - coors[0][1])/(coors[1][0] - coors[0][0]) # guaranteed not a vertical line
        b = coors[0][1] - m * coors[0][0]
        # print(m,b)
        
        for i in range(N-1):    # exclude the last one
            if coors[i][0] == coors[i+1][0]:    # verticalness detected
                return False
            tm = (coors[i][1] - coors[i+1][1])/(coors[i][0] - coors[i+1][0])
            tb = coors[i][1] - m * coors[i][0]
            if tm != m or tb != b:
                return False
        return True
