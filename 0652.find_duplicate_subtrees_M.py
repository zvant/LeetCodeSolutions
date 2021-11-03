# https://leetcode.com/problems/find-duplicate-subtrees/
# 2021/10
# 68 ms

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findDuplicateSubtrees(self, root: Optional[TreeNode]) -> List[Optional[TreeNode]]:
        S = [(root, False)]
        all_nodes = {}
        while len(S) > 0:
            t, visited = S.pop()
            if t is None:
                continue
            if not visited:
                S.append([t, True])
                S.append([t.left, False])
                S.append([t.right, False])
            else:
                t.hash = '(%s-%d-%s)' % ('' if t.left is None else t.left.hash, t.val, '' if t.right is None else t.right.hash)
                if not t.hash in all_nodes:
                    all_nodes[t.hash] = []
                all_nodes[t.hash].append(t)
        results = []
        for k in all_nodes:
            if len(all_nodes[k]) > 1:
                results.append(all_nodes[k][0])
        return results
