"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        que = collections.deque()
        res = []
        if root == None:
            return res
        que.appendleft(root)
        
        while len(que) != 0:    # que is not empty
            size = len(que)
            level = []
            for i in range (0, size):
                curr = que.pop()
                level.append(curr.val)
                for kid in curr.children:   # same thing as 102, except this time we 
                    que.appendleft(kid) # have more children to add (not always 0,1, or 2)
            res.append(level)
        return res
