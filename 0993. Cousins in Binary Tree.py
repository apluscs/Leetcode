# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    dx = 0
    dy = 0
    x = 0
    y = 0
    px = 0
    py = 0
    
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        self.x = x
        self.y = y
        self.helper(root, 0, -1)
        return self.dx == self.dy and self.px != self.py
    
    def helper(self, curr: TreeNode, depth: int, parent: int) -> bool:
        if curr == None:
            return
        if curr.val == self.x:  # found x!
            self.dx = depth     # now record depth and parent
            self.px = parent
        if curr.val == self.y:
            self.dy = depth
            self.py = parent
        self.helper(curr.left, depth + 1, curr.val)
        self.helper(curr.right, depth + 1, curr.val)
            
            
            
