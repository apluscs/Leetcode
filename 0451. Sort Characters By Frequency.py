# next time try this https://leetcode.com/problems/sort-characters-by-frequency/discuss/93404/C%2B%2B-O(n)-solution-without-sort()

class Solution:
    
    def frequencySort(self, s: str) -> str:
        frq = [ [ 0 for i in range(2) ] for j in range(126) ] 
        for i in range(126):
            frq[i][1] = i   # record original index (what char it is)
        for c in s:
            frq[ord(c)][0] += 1
        frq.sort(key = lambda f: f[0], reverse = True)
        # print(frq)
        res = ""
        for f in frq:
            for i in range(f[0]):   # occurences of this char
                res += chr(f[1])    # add this char that many times
        
        return res
        
