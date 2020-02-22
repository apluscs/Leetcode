# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        que = collections.deque()
        res = []
        if root == None:
            return res
        que.appendleft(root)
        
        while len(que) != 0:    # que is not empty
            size = len(que)
            total = 0
            for i in range (0, size):
                curr = que.pop()
                total += curr.val   # sum up vals of this level
                if curr.left != None:
                    que.appendleft(curr.left)
                if curr.right != None:
                    que.appendleft(curr.right)
            res.append(total/size)
            
        return res
