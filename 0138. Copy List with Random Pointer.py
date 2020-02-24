"""
# Definition for a Node.
class Node:
    def __init__(self, x: int, next: 'Node' = None, random: 'Node' = None):
        self.val = int(x)
        self.next = next
        self.random = random
"""
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        mapp = {}   # map old nodes to new nodes
        h = g = head
        while h != None:
            mapp[h] = Node(h.val)
            h = h.next
        mapp[None] = None   # one case that didn't get taken care of by while loop
        
        while g != None:    # still traversing through old list
            curr = mapp[g]
            curr.next = mapp[g.next]    # new nodes representing old nodes
            curr.random = mapp[g.random]
            g = g.next
        return mapp[head]
