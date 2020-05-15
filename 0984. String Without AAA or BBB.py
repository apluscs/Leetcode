class Solution:
    def strWithout3a3b(self, A: int, B: int) -> str:
        res,i="",0
        while A or B:
            can_put_A=A>0 and (len(res)<2 or res[-1]!='a' or res[-2]!='a')
            can_put_B=B>0 and (len(res)<2 or res[-1]!='b' or res[-2]!='b')
            if A>=B:
                if can_put_A:
                    res+='a'
                    A-=1
                else:
                    res+='b'
                    B-=1
            else:   #b is majority
                if can_put_B:
                    res+='b'
                    B-=1
                else:
                    res+='a'
                    A-=1
        return res
