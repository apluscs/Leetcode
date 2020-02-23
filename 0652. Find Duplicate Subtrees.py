# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    once = {}
    
    
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        self.once = {} # clear it
        res = []
        self.helper(root)
        for key, value in self.once.items():
            if value[1] > 1:
                res.append(value[0])
        return res
    
    def helper(self, curr: TreeNode) -> str:
        if curr == None:
            return ""
        lt = "" if curr.left == None else "(" + self.helper(curr.left) + ")"
        rt = "" if curr.right == None else "(" + self.helper(curr.right) + ")"
        if curr.right != None and curr.left == None:    # one case you need empty parenthesis
            lt = "()"   # pulled from 606
        curr_id = str(curr.val) + lt + rt   # key in once
        count = 1 if curr_id not in self.once else self.once[curr_id][1] + 1
        self.once[curr_id] = [curr, count]  # need to track the actual TreeNode
        return curr_id
        
