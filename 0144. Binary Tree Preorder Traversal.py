# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def preorderTraversal(self, root: TreeNode) -> List[int]:
        res=[]
        while root:
            curr=root.left
            if not curr:
                res.append(root.val)
                root=root.right
                continue
            while curr.right and curr.right!=root:
                curr=curr.right
            if curr.right==None:    #first time visting this inorder predecessor; root should be added now
                res.append(root.val)
                curr.right=root
                root=root.left
            else:   #we visited root before, then connected this predecessor to root, then visited the predecessor, then went to root the second time. Now when we search for the predecessor, we see we found it already the first time, so we know we've already visted the LHS + root, so we can move onto the RHS
                curr.right=None
                root=root.right
        return res
            
