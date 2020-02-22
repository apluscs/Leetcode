# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:
        res = []
        if root == None:
            return res
        que = collections.deque()
        que.appendleft(root)
        
        while( len(que) != 0):
            size = len(que)
            largest = -sys.maxsize - 1  # min int value
            for i in range(0, size):    # process all nodes at this level of the tree
                curr = que.pop()    # from the right side
                largest = max(largest, curr.val)
                if(curr.left != None):
                    que.appendleft(curr.left)
                if(curr.right != None):
                    que.appendleft(curr.right)
            res.append(largest)
        
        return res
