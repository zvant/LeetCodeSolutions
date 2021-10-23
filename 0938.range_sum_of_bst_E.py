# https://leetcode.com/problems/range-sum-of-bst/
# 2021/10
# 288 ms

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
# class Solution:
#     def BFS(self, root, L, R):
#         if root is None:
#             return
#         if root.val > L:
#             self.BFS(root.left, L, R)
#         if root.val < R:
#             self.BFS(root.right, L, R)
#         if root.val >= L and root.val <= R:
#             self.summary += root.val
#     def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
#         self.summary = 0
#         self.BFS(root, L, R)
#         return self.summary
class Solution:
    def rangeSumBST(self, root: TreeNode, L: int, R: int) -> int:
        total = 0
        S = [root]
        while len(S) > 0:
            node = S.pop()
            if not node is None:
                x = node.val
                if x >= L and x <= R:
                    total += x
                S.append(node.left)
                S.append(node.right)
        return total
