# https://leetcode.com/problems/increasing-order-search-tree/
# 2021/10
# 32 ms

class Solution:
    def increasingBST(self, root: TreeNode) -> TreeNode:
        nodes, S = [], [(root, False)]
        while len(S) > 0:
            n, visited = S.pop()
            if n is None:
                continue
            if visited:
                nodes.append(n)
            else:
                S.append((n.right, False))
                S.append((n, True))
                S.append((n.left, False))
        for i in range(0, len(nodes) - 1):
            nodes[i].left = None
            nodes[i].right = nodes[i + 1]
        nodes[-1].left = nodes[-1].right = None
        return nodes[0]
