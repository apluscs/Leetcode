# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rob(self, root: TreeNode) -> int:
        res = self.helper(root)
        return res[0]
    
    def helper(self, curr: TreeNode) -> List[int]:
        if curr == None:
            return [0,0]
        a, b = self.helper(curr.left), self.helper(curr.right)
        c = a[0] + b[0] # profit from both kids
        res = [max(c, curr.val + a[1] + b[1]), c ]  # res[0] = answer for this one = either take kids or take yourself AND all grandkids
        return res
        
