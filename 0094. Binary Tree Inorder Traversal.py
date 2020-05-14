# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res=[]
        while root:
            curr=root.left
            if not curr:    #no left child
                res.append(root.val)
                root=root.right
                continue
            while curr.right and curr.right!=root:
                curr=curr.right #find inorder successor
            if curr.right==root:    #we strung this to root before, when we were at root. Then we visited this before and took its right path, which led us back to root again. We found its inorder successor the second time, which tells us we had visited root before but not processed it. Now that we know we've visited this entire LHS (curr.right is the maximal of it), we can finally process root
                curr.right=None
                res.append(root.val)
                root=root.right
            else:
                curr.right=root
                root=root.left
        return res
        
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution_Iterative:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res,st=[],deque()
        while len(st) or root:
            while root: #if root has reached the end, the stack saves the inorder successor
                st.append(root)
                root=root.left
            root=st.pop()
            res.append(root.val)
            root=root.right
            
        return res
        
