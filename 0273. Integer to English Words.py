class Solution:
    def numberToWords(self, num: int) -> str:
        if num==0:
            return "Zero"
        suff=[""," Thousand"," Million"," Billion"]
        pre=[""," One"," Two"," Three"," Four"," Five"," Six"," Seven", " Eight", " Nine"]
        deci=["",""," Twenty"," Thirty"," Forty"," Fifty"," Sixty", " Seventy"," Eighty"," Ninety"]
        teens=[" Ten"," Eleven"," Twelve"," Thirteen"," Fourteen"," Fifteen"," Sixteen"," Seventeen"," Eighteen"," Nineteen"]
        res=""
        def solve(num:int)->str:
            res=""
            if num>=100:
                res+=str(pre[num//100])+" Hundred"
                num %=100
            if num>=20:
                res+=str(deci[num//10])
                num%=10
                res+=pre[num]
            elif num>=10:
                res+=teens[int(num-10)]
            else:
                res+=pre[num]
            return res
        
        i=0
        while num!=0:
            x=num%1000
            num//=1000
            # print(suff[i],x)
            if x!=0:
                res=solve(x)+suff[i]+res
            i+=1
        return res.strip()
            
