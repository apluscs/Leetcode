# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        nums = []
        def inorder(curr: TreeNode) -> None:
            if curr == None:
                return
            inorder(curr.left)
            nums.append(curr.val)
            inorder(curr.right)
        
        inorder(root)
        # print(nums)
        N = len(nums)
        def makeTree(low: int, high: int) -> TreeNode:
            if low > high:
                return None
            mid = (low + high) >> 1
            root = TreeNode(nums[mid])
            root.left = makeTree(low, mid - 1)
            root.right = makeTree(mid + 1, high)
            return root
        
        return makeTree(0, N-1)
        
