# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:    # from 449
    
    def serialize(self, curr):
        if curr == None:
            return ""
        lt = "" if curr.left == None else "(" + self.serialize(curr.left) + ")"
        rt = "" if curr.right == None else "(" + self.serialize(curr.right) + ")"
        if curr.right != None and curr.left == None:    # one case you need empty parenthesis
            lt = "()"   # from 606
        return str(curr.val) + lt + rt
        

    def deserialize(self, data):
        if data == "":
            return None
        start = data.find('(')
        if start == -1:
            start = len(data)
        root = TreeNode(int(data[:start]))  # first value
        bal = 1
        left_found = False
        for i in range(start+1,len(data)):  # start beyond first '('
            if data[i] == '(':
                bal += 1
            elif data[i] == ')':
                bal -= 1
            if bal == 0:    # only when i = ')'
                child_str = data[start+1:i] # exclude last ')'
                child = self.deserialize(child_str)
                if left_found:
                    root.right = child
                else:
                    root.left = child
                left_found = True
                start = i+1
        return root
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
