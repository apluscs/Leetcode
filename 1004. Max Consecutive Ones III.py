class Solution:
    def longestOnes(self, A: List[int], k: int) -> int:
        n,i,j,count,res=len(A),0,0,0,0
        while i!=n:
            while i!=n:
                count+=1-A[i]
                i+=1
                if(count<=k):
                    res=max(res,i-j)
                else:
                    break
            while count>k:
                count-=1-A[j]
                j+=1
        return res
