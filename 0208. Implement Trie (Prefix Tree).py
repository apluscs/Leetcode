class Trie:
    class Node:
        def __init__(self):
            self.kids = []
            self.isValid = False
            self.isEnd = False
    def __init__(self):
        self.root = self.Node()        

    def insert(self, word: str) -> None:
        def helper(curr: self.Node, pos: int) -> None:  # one of curr's children will represent word[pos]
            if curr.kids == []: 
                curr.kids = [self.Node() for i in range(26)]
            c = ord(word[pos]) - ord('a')
            curr.kids[c].isValid = True
            if pos == len(word) - 1:
                curr.kids[c].isEnd = True
                return
            helper(curr.kids[c], pos + 1)
            
        helper(self.root, 0)
        
    def search(self, word: str) -> bool:
        def helper(curr: self.Node, pos: int) -> None:  # curr's children will represent word[pos]
            if curr.kids == []: # cannot go further
                return False
            c = ord(word[pos]) - ord('a')
            if not curr.kids[c].isValid:
                return False
            if pos == len(word) - 1:
                return curr.kids[c].isEnd   # need this to end
            return helper(curr.kids[c], pos + 1)
            
        return helper(self.root, 0)
        

    def startsWith(self, word: str) -> bool:
        def helper(curr: self.Node, pos: int) -> None:  # curr's children will represent word[pos]
            if curr.kids == []:
                return False
            c = ord(word[pos]) - ord('a')
            if not curr.kids[c].isValid:
                return False
            if pos == len(word) - 1:
                return True # last char is valid (else we would have returned)
            return helper(curr.kids[c], pos + 1)
            
        return helper(self.root, 0)
    

# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
