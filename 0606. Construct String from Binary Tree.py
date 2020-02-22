# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def tree2str(self, curr: TreeNode) -> str:
        if curr == None:
            return ""
        lt = "" if curr.left == None else "(" + self.tree2str(curr.left) + ")"
        rt = "" if curr.right == None else "(" + self.tree2str(curr.right) + ")"
        if curr.right != None and curr.left == None:    # one case you need empty parenthesis
            lt = "()"   # if the case (P(C)), this indicates parent is C is left (default)
        return str(curr.val) + lt + rt
