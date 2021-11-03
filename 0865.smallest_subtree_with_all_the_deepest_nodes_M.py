# https://leetcode.com/problems/smallest-subtree-with-all-the-deepest-nodes/
# 2021/10
# 36 ms

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        Q = [root]
        while True:
            Q2 = []
            for n in Q:
                for child in [n.left, n.right]:
                    if not child is None:
                        child.parent = n
                        Q2.append(child)
            if len(Q2) < 1:
                break
            else:
                Q = Q2
        while len(Q) > 1:
            Q2 = [Q[0].parent]
            for n in Q:
                p = n.parent
                if p != Q2[-1]:
                    Q2.append(p)
            Q = Q2
        return Q[0]
