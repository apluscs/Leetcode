class Solution:
    def prevPermOpt1(self, A: List[int]) -> List[int]:
        inds={}
        n=len(A)
        for i in range(n-1,-1,-1):
            x,best=A[i],0
            for k in inds:
                if k<x:
                    best=max(best,k)
            if best!=0:        
                A[i]=A[inds[best]]
                A[inds[best]]=x
                return A
            inds[x]=i

        return A
