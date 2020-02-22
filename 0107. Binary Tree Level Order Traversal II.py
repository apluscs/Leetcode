# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrderBottom(self, root: TreeNode) -> List[List[int]]:
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
                if curr.left != None:
                    que.appendleft(curr.left)
                if curr.right != None:
                    que.appendleft(curr.right)
            res.append(level)
        res.reverse()   # same thing as #102, except you reverse it at the end
        return res
