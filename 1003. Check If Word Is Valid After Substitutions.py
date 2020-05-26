class Solution:
    def isValid(self, S: str) -> bool:
        if S == "":
            return True
        for i in range(len(S)-2):
            if S[i:i+3] == "abc":
                return self.isValid(S[:i]+S[i+3:])
        return False
