

class Solution: #376 ms
    
    def minStickers(self, stickers: List[str], target: str) -> int:

        t_count = collections.Counter(target)        
        A = [collections.Counter(sticker) & t_count for sticker in stickers]
        for i in range(len(A) - 1, -1, -1):
            if any(A[i] == A[i] & A[j] for j in range(len(A)) if i != j):
                A.pop(i)    # goes from back to front so it's ok

        self.best=len(target)
        self.n=len(A)
        for c in target:
            found=False
            for s in stickers:
                if c in s:
                    found=True
                    break
            if not found:
                return -1
        
                
        def solve(used:int,i:int) -> int:
            # print(i)
            if i==self.n:
                if all(t_count[x]<=0 for x in t_count):
                    self.best=min(self.best,used)
                return
            # print(stickers[i]+" "+str(used))
            if used >=self.best:
                return  #early pruning
            sticker=A[i]   # a counter
            x=max(t_count[letter]  // sticker[letter]
                        for letter in sticker)
            x=max(x,0)
            
            for c in sticker:
                t_count[c]-=x*sticker[c]
                print(c,sticker[c])
            solve(used+x,i+1)
            for j in range(x-1,-1,-1):
                for letter in sticker:
                    t_count[letter]+=sticker[letter]
                solve(used+j,i+1)
            
        solve(0,0)
        return self.best

class Solution: # very slow, but used DFS
    
    def minStickers(self, stickers: List[str], target: str) -> int:
        def get_frq(target:str) -> List[int]:
            res=[0]*26
            for c in target:
                res[ord(c)-ord('a')]+=1
            return res
        self.frq=get_frq(target)
        # print(self.frq)
        self.best=len(target)
        self.n=len(stickers)
        for c in target:
            found=False
            for s in stickers:
                if c in s:
                    found=True
                    break
            if not found:
                return -1
        
                
        def solve(used:int,i:int) -> int:
            
            if i==self.n:
                if sum(self.frq)==0:
                    print("END "+str(used))
                    self.best=min(self.best,used)
                return
            # print(stickers[i]+" "+str(used))
            if used >=self.best:
                return  #early pruning
            sfrq=get_frq(stickers[i])
            
            x=0
            for j in range(26):
                if sfrq[j]==0:
                    continue
                x=max(x,self.frq[j]//sfrq[j])
                
            for j in range(x,-1,-1):
                temp=self.frq.copy()
                for k in range(26): # appply this sticker j times
                    self.frq[k]=max(0,self.frq[k]-j*sfrq[k])
                # print("applied "+stickers[i]+" "+str(j)+" times")
                solve(used+j,i+1)
                self.frq=temp.copy()
            
        solve(0,0)
        return self.best

class Solution: #25% for python time, dp based on chars left
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
