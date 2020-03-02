# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rightSideView(self, root: TreeNode) -> List[int]:
        que = collections.deque()
        que.appendleft(root)
        res = []
        if root == None:
            return res
        while len(que) != 0:
            sz = len(que)
            curr = que.pop()
            res.append(curr.val)    # first one in the queue is the rightmost one of last layer
            if curr.right != None:
                que.appendleft(curr.right)
            if curr.left != None:
                que.appendleft(curr.left)
            for i in range(sz-1):   # count the rightmost node you already popped out
                curr = que.pop()
                if curr.right != None:
                    que.appendleft(curr.right)
                if curr.left != None:
                    que.appendleft(curr.left)
        return res
