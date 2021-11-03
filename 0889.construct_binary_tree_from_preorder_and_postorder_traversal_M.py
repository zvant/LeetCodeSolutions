# https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/
# 2021/10
# 48 ms

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def constructFromPrePost(self, preorder: List[int], postorder: List[int]) -> Optional[TreeNode]:
        def construct(i1, i2, j1, j2):
            if i1 >= i2:
                return None
            node = TreeNode(preorder[i1])
            if i1 == i2 - 2:
                node.left = TreeNode(preorder[i1 + 1])
            elif i2 - i1 > 2:
                i1, j2 = i1 + 1, j2 - 1
                val, k = preorder[i1], 0
                while val != postorder[j1 + k]:
                    k += 1
                k += 1
                node.left = construct(i1, i1 + k, j1, j1 + k)
                node.right = construct(i1 + k, i2, j1 + k, j2)
            return node
        return construct(0, len(preorder), 0, len(postorder))
