class Solution:
    
    def minStickers(self, stickers: List[str], target: str) -> int:
        self.dp={}
        self.frq=[0]*26
        n,best=len(target),len(target)
        for c in target:
            found=False
            for s in stickers:
                if c in s:
                    found=True
                    break
            if not found:
                return -1
            self.frq[ord(c)-ord('a')]+=1
        self.dp[""]=0
        def get_id() -> string:
            res=""
            for i in range(26):
                if self.frq[i]==0:
                    continue
                res+= chr(i+ord('a'))+ str(self.frq[i])
            return res
                
        def solve() -> int:
            di=get_id()
            # print(di)
            if di in self.dp:
                return self.dp[di]
            res=15
            for s in stickers:
                temp=self.frq.copy()
                found=False
                for c in s:
                    if self.frq[ord(c)-ord('a')]>0:
                        self.frq[ord(c)-ord('a')]-=1
                        found=True
                if not found:
                    continue
                res=min(res,solve()+1)
                self.frq=temp.copy()
            self.dp[di]=res
            return res
        return solve()
