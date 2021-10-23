# https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
# 2021/10
# 28 ms

# HARD ???

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        if root is None:
            return []
        S, values = [(root, 0, 0)], {}
        while len(S) > 0:
            node, row, col = S.pop()
            if not col in values:
                values[col] = {}
            if not row in values[col]:
                values[col][row] = []
            values[col][row].append(node.val)
            if not node.left is None:
                S.append((node.left, row + 1, col - 1))
            if not node.right is None:
                S.append((node.right, row + 1, col + 1))
        results = []
        for col in sorted(values.keys()):
            nums_col = []
            for row in sorted(values[col].keys()):
                nums_col = nums_col + sorted(values[col][row])
            if len(nums_col) > 0:
                results.append(nums_col)
        return results
