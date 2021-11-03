# https://leetcode.com/problems/longest-univalue-path/
# 2021/10
# 496 ms

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def longestUnivaluePath(self, root: Optional[TreeNode]) -> int:
        max_uni_len = 0
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
                max_len_left = 1 + t.left.down_max_len if not t.left is None and t.left.val == t.val else 0
                max_len_right = 1 + t.right.down_max_len if not t.right is None and t.right.val == t.val else 0
                t.down_max_len = max(max_len_left, max_len_right) # max uni length down-ward
                max_uni_len = max(max_len_left + max_len_right, max_uni_len)
        return max_uni_len
