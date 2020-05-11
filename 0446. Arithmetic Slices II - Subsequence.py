// c++ was too slow, even though I basically did the same thing, was also O(N^2) 
// sad life :/
class Solution:
    def numberOfArithmeticSlices(self, A: List[int]) -> int:
        n,res=len(A),0
        dp=[{} for i in range(n)]   #dp[i][j]= number of subsequences ending in pos i with diff = j
        for i in range(n):
            for j in range(i):
                diff=A[i]-A[j]
                if diff not in dp[i]:
                    dp[i][diff]=0
                dp[i][diff]+=1
                if diff in dp[j]:
                    dp[i][diff]+=dp[j][diff]
                    res+=dp[j][diff]
                
        return res
