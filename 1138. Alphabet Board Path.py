class Solution:
    def alphabetBoardPath(self, target: str) -> str:
        
        def helper(a: int, b: int) -> str:
            ai, aj, bi, bj = int(a/5), a % 5, int(b/5), b % 5
            res = ""
            for i in range(aj - bj):    # move left before right, in case we go off the board trying to get to 'z'
                res += "L"
            for i in range(ai-bi):      # move up before down, in case we go off the board trying to get away from 'z'
                res += "U"
            for i in range(bj - aj):    
                res += "R"
            for i in range(bi-ai):
                res += "D"
            
            return res
        
        res = ""
        prev = 0    # first letter we start with
        for c in target:
            res += helper(prev, ord(c)-ord('a')) + "!" # move from prev to this new letter
            prev = ord(c)-ord('a')
        return res
        
        # map each letter to its location
        # helper(a, b) should return a str that is shortest path from a to b
        # every unit b is above a, put down 'U'; below = 'D'
        # every unit b is right of a, put down 'R'; left = 'L'
