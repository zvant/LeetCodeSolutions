'''
https://leetcode.com/problems/binary-tree-postorder-traversal/
2021/10
32 ms
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        seq = []
        S = [[root, False]]
        while len(S) > 0:
            if S[-1][0] is None:
                S.pop()
                continue
            if not S[-1][1]:
                S[-1][1] = True
                S.append([S[-1][0].right, False])
                S.append([S[-2][0].left, False])
            else:
                seq.append(S[-1][0].val)
                S.pop()
        return seq
