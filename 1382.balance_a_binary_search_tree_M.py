# https://leetcode.com/problems/balance-a-binary-search-tree/
# 2021/10
# 340 ms

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def balanceBST(self, root: TreeNode) -> TreeNode:
        nodes, S = [], [(root, False)]
        while len(S) > 0:
            n, visited = S.pop()
            if n is None:
                continue
            if visited:
                nodes.append(n)
            else:
                S.append((n.right, False))
                S.append((n, True))
                S.append((n.left, False))
        root_new = TreeNode(-1)
        S = [(0, len(nodes), root_new, True)]
        while len(S) > 0:
            i1, i2, parent, is_left = S.pop()
            if i1 >= i2:
                n = None
            else:
                mid = (i1 + i2) // 2
                n = nodes[mid]
                n.left = n.right = None
                S.append((i1, mid, n, True))
                S.append((mid + 1, i2, n, False))
            if is_left:
                parent.left = n
            else:
                parent.right = n
        return root_new.left
