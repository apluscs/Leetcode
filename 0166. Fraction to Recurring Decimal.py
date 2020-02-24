class Solution:
    def fractionToDecimal(self, top: int, bottom: int) -> str:
        if top == 0:    # special case: 0/ neg num
            return "0"
        neg = (top < 0) ^ (bottom < 0)  # only true if exactly 1 of top or bottom is neg
        top = abs(top)
        bottom = abs(bottom)
        pre = ("-" if neg else "") + str(int(top/bottom)) + "."
        top = (top % bottom) * 10
        if top == 0:    # perfectly divisible
            return pre[:-1] # all except final '.'
        mapp = {}   # mapp[num] = index in post-decimal-point string of a quotient that top produced the first time around  
        i = 0
        post = ""   # part after the decimal point
        while top != 0:
            curr = top/bottom
            mapp[top] = len(post)
            post += str(int(curr))  # cut off post decimal point
            top = (top % bottom) * 10
            if top in mapp:
                post = post[:mapp[top]] + "(" + post[mapp[top]:] + ")"
                break
        return pre + post
