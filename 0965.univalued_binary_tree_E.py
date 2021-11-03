# https://leetcode.com/problems/univalued-binary-tree/
# 2021/10
# 32 ms

class Solution:
    def isUnivalTree(self, root: Optional[TreeNode]) -> bool:
        val, S = root.val, [root]
        while len(S) > 0:
            n = S.pop()
            if n is None:
                continue
            if n.val != val:
                return False
            S.append(n.left)
            S.append(n.right)
        return True
