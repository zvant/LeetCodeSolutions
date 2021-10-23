'''
https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
20121/10
32 ms
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import deque
class Solution:
    def DFS(self, root, target):
        S = [root]
        while True:
            node = S.pop()
            path.append(node)
            if node == target:
                return
            for child in [node.left, node.right]:
                if not child is None:
                    child.parent = node
                    S.append(child)
    def BFS(self, root, depth):
        Q = deque([(root, 0)])
        visited = set([root.val])
        while len(Q) > 0:
            curr_depth = Q[0][1]
            if curr_depth == depth:
                return list(Q)
            while len(Q) > 0 and Q[0][1] == curr_depth:
                node = Q.popleft()[0]
                neighbors = [node.left, node.right]
                if hasattr(node, 'parent'):
                    neighbors.append(node.parent)
                for n in neighbors:
                    if not n is None and not n.val in visited:
                        visited.add(n.val)
                        Q.append((n, curr_depth + 1))
        return []
    def distanceK(self, root: TreeNode, target: TreeNode, k: int) -> List[int]:
        if k == 0:
            return [target.val]
        self.DFS(root, target)
        results = self.BFS(target, k)
        return list(map(lambda x: x[0].val, results))
