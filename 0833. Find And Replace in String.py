from cStringIO import StringIO
class Solution(object):
    def opComparator(self,op):
        return op[0]    #sort by index in S so can can go left to right
    def findReplaceString(self, S, indexes, sources, targets):
        """
        :type S: str
        :type indexes: List[int]
        :type sources: List[str]
        :type targets: List[str]
        :rtype: str
        """
        N=len(indexes)
        ops=[]
        for i in range(N):
            ops.append([indexes[i],sources[i],targets[i]])  #python allows array elems to be of different types (why I used it lol)
        ops.sort(key=self.opComparator) #class method, must prefix with self.
        ops.append([len(S)])
        res=StringIO()  #writing to a pseudo file, much faster than string concatentation
        res.write(S[:ops[0][0]])    #whatever comes before first index to examine
        for i in range(N):
            op=ops[i]
            leng=len(op[1])
            found=S[op[0]:op[0]+leng]   
            if found==op[1]:
                res.write(op[2])    #we should replace
            else:
                res.write(found)    #accept the default
            res.write(S[op[0]+leng:ops[i+1][0]])    #everything from here to next index to examine (this part is not checked as source)
        return res.getvalue()
    
    
    
    
