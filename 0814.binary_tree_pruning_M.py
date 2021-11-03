# https://leetcode.com/problems/binary-tree-pruning/
# 2021/10
# 32 ms

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def pruneTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        S = [(root, False)]
        while len(S) > 0:
            t, visited = S.pop()
            if t is None:
                continue
            if not visited:
                S.append((t, True))
                S.append((t.left, False))
                S.append((t.right, False))
            else:
                if not t.left is None and not t.left.valid:
                    t.left = None
                if not t.right is None and not t.right.valid:
                    t.right = None
                if t.val == 0 and t.left is None and t.right is None:
                    t.valid = False
                else:
                    t.valid = True
        if not root.valid:
            root = None
        return root
