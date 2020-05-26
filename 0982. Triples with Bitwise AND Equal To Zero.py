class Solution:
    def countTriplets(self, A: List[int]) -> int:
        a,b,n,res={},{},len(A),0
        for x in A:
            for k in b: # AND of two numbers
                if k&x==0:
                    res+=b[k]*3 #number of pairs of this good AND
            for k in a: # all previous values
                y=x&k
                if y not in b:
                    b[y]=0
                b[y]+=2*a[k] #2 possible permutations for every k seen
                if y==0:
                    res+=3*a[k]
            if x==0:
                res+=1
            if x not in a:
                a[x]=0
            a[x]+=1

            
            if x not in b:
                b[x]=0
            b[x]+=1 
            # print(res,a,b)
        return res
                
    '''
    a: 2,1
    
    b: 2,2

    '''
