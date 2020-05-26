class Solution:
    def smallestStringWithSwaps(self, s: str, pairs: List[List[int]]) -> str:
        N = len(s)
        reps = [-1] * N
        def union(a: int, b: int) -> None:
            pa, pb = find(a), find(b)   # find the parent of both
            if pa != pb:
                reps[pa] = pb
            while a != pa:  # path compression
                temp = reps[a]
                reps[a] = pb
                a = temp
            
        def find(a: int) -> int:
            while reps[a] != -1:
                a = reps[a]
            return a
        
        for p in pairs:
            union(p[0], p[1])   # union all of them
        chars = [ [] for i in range(N) ]
        
        for i in range(N):
            chars[find(i)].append(s[i]) # map each parent to all chars in its subgraph
        for i in range(N):  # smallest at the end
            chars[i].sort(reverse = True)
        res = ""
        for i in range(N):  # indexes closer to 0 have higher priority
            res += chars[find(i)].pop() # go to collection of chars of i's subgraph, choose the smallest possible
        
        return res
