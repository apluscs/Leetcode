class WordDictionary:
    class Node:
        def __init__(self):
            self.isValid = False
            self.isEnd = False
            self.kids = []
    def __init__(self):
        self.root = self.Node()
        

    def addWord(self, word: str) -> None:
        def helper(curr: self.Node(), pos: int) -> None:
            if curr.kids == []:
                curr.kids = [self.Node() for i in range(26)]
            c = ord(word[pos]) - ord('a')
            
            if word[pos] == '.':    # every path from here is valid
                for kid in curr.kids:
                    kid.isValid = True
            else:
                curr.kids[c].isValid = True
            if pos == len(word) - 1:
                if word[pos] == '.':    # every end is possible
                    for kid in curr.kids:
                        kid.isEnd = True
                else:
                    curr.kids[c].isEnd = True
                return
            if word[pos] == '.':
                for kid in curr.kids:   # recur on every kid
                    helper(kid, pos + 1)
            else:
                helper(curr.kids[c], pos + 1)
        helper(self.root, 0)
        

    def search(self, word: str) -> bool:
        def helper(curr: self.Node(), pos: int):
            if curr.kids == []:
                return False
            if pos == len(word) - 1:
                if word[pos] == '.':
                    for kid in curr.kids:
                        if kid.isEnd:
                            return True
                    return False
                else:
                    c = ord(word[pos]) - ord('a')
                    return curr.kids[c].isEnd
            if word[pos] == '.':    # try any kid that is valid
                for kid in curr.kids:
                    if kid.isValid and helper(kid, pos + 1):
                        return True
            else:
                c = ord(word[pos]) - ord('a')
                if curr.kids[c].isValid:
                    return helper(curr.kids[c], pos + 1)
            return False
        if word == "":    
            return False
        return helper(self.root, 0)

# Your WordDictionary object will be instantiated and called as such:
# obj = WordDictionary()
# obj.addWord(word)
# param_2 = obj.search(word)
