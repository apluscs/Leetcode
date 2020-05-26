# could be faster
# math major did this one

from math import sqrt
from fractions import Fraction as frac
class Solution:
    def maxPoints(self, points: List[List[int]]) -> int:
        pointdict=dict()
        eps=1e-10
        for (x,y) in points:
            if (x,y) in pointdict.keys():
                pointdict[(x,y)]+=1
            else:
                pointdict[(x,y)]=1
        n=len(pointdict)
        if n == 0:
            return 0
        elif n == 1:
            return len(points)
        pointlist=list(pointdict.items())
        linelist=set()
        for j in range(n):
            for i in range(j):
                [x0,y0]=pointlist[i][0]
                [x1,y1]=pointlist[j][0]
                if x1 != x0:
                    i=0
                    m=frac(y1-y0,x1-x0)
                    b=y0-m*x0
                else:
                    i=1
                    m=frac(x0,1)
                    b=0
                linelist.add((i,m,b))
        maxpointcount=0
        for line in linelist:
            (q,m,b)=line
            pointcount=0
            for i in range(n):
                (x,y)=pointlist[i][0]
                if q == 0 and y==m*x+b:
                    pointcount+=pointlist[i][1]
                if q == 1 and x==m:
                    pointcount+=pointlist[i][1]
            maxpointcount=max(maxpointcount,pointcount)
        return maxpointcount
        
