# https://leetcode.com/problems/first-unique-character-in-a-string/discuss/86351/Python-3-lines-beats-100-(~-60ms)-! 
# much faster for some reason

class Solution:
    def firstUniqChar(self, s: str) -> int:
        frq = [0]*26
        for c in s:
            frq[ord(c)-ord('a')] += 1
            
        for i in range(len(s)):
            if frq[ord(s[i])-ord('a')] == 1:
                return i
        return -1
