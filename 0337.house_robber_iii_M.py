# https://leetcode.com/problems/house-robber-iii/
# 2021/10
# 48 ms

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def DFS(self, root):
        if root is None:
            return {'robbed': 0, 'not_robbed': 0}
        if not hasattr(root, 'max_cash'):
            root.max_cash = {}
            if root.left is None and root.right is None:
                root.max_cash['robbed'] = root.val
                root.max_cash['not_robbed'] = 0
            else:
                max_cash_left, max_cash_right = self.DFS(root.left), self.DFS(root.right)
                root.max_cash['robbed'] = root.val + max_cash_left['not_robbed'] + max_cash_right['not_robbed']
                root.max_cash['not_robbed'] = max(max_cash_left['robbed'], max_cash_left['not_robbed']) + max(max_cash_right['robbed'], max_cash_right['not_robbed'])
        return root.max_cash
    def rob(self, root: Optional[TreeNode]) -> int:
        max_cash = self.DFS(root)
        return max(max_cash['robbed'], max_cash['not_robbed'])
