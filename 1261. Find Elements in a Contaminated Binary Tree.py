# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class FindElements:
    root = None
    seen = set()
    def __init__(self, root: TreeNode):
        self.root = root
        self.seen = set()
        def helper(self, curr: TreeNode, val: int):
            if curr == None:
                return
            curr.val = val
            self.seen.add(val)  #mark val as something in the tree
            helper(self, curr.left, 2*val + 1)
            helper(self, curr.right, 2*val + 2)
        helper(self, root, 0)   # starts off as 0

    def find(self, target: int) -> bool:
        return target in self.seen


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)
