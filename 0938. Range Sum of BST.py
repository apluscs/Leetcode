# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    res = 0
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        self.res = 0
        self.helper(root, L, R) # need another function to set res = 0
        return self.res
    
    def helper(self, curr: TreeNode, L: int, R: int):
        if curr == None:
            return
        self.res += 0 if curr.val < L or curr.val > R else curr.val
        self.helper(curr.left, L, R)
        self.helper(curr.right, L, R)
        
