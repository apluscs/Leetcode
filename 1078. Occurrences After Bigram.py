class Solution:
    def findOcurrences(self, text: str, first: str, second: str) -> List[str]:
        words, res = text.split(), []
        N = len(words)
        for i in range(N-2):    # last one accessed is third to last word
            if words[i] == first and words[i+1] == second:
                res.append(words[i+2])
        return res
