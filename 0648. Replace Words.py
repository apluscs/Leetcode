class Solution:
    def replaceWords(self, dict: List[str], sentence: str) -> str:
        roots = set()
        maxlen = 0
        for root in dict:
            roots.add(root)
            maxlen = max(maxlen, len(root))
        words = sentence.split()
        for i in range(len(words)):
            curr = ""
            for j in range(min(maxlen, len(words[i]))): # try every possible prefix
                curr += words[i][j]
                if curr in roots:   # is the first j letters of words[i] a valid root?
                    words[i] = curr
                    break
        return ' '.join(words)
