# https://leetcode.com/problems/leaf-similar-trees/
# 2021/10
# 28 ms

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def leafSimilar(self, root1: Optional[TreeNode], root2: Optional[TreeNode]) -> bool:
        S1, S2 = [root1], [root2]
        while len(S1) > 0 and len(S2) > 0:
            leaf1, leaf2 = None, None
            while True:
                n = S1.pop()
                if n.left is None and n.right is None:
                    leaf1 = n.val
                    break
                for child in [n.left, n.right]:
                    if not child is None:
                        S1.append(child)
            while True:
                n = S2.pop()
                if n.left is None and n.right is None:
                    leaf2 = n.val
                    break
                for child in [n.left, n.right]:
                    if not child is None:
                        S2.append(child)
            if leaf1 != leaf2:
                return False
        if len(S1) != len(S2):
            return False
        return True
