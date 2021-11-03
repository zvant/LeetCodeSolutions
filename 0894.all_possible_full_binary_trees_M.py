# https://leetcode.com/problems/all-possible-full-binary-trees/
# 2021/10
# 580 ms

class Solution:
    def allPossibleFBT(self, n: int) -> List[Optional[TreeNode]]:
        def copy_BT(t):
            if t is None:
                return None
            t1 = TreeNode(t.val)
            t1.left = copy_BT(t.left)
            t1.right = copy_BT(t.right)
            return t1
        
        def hash_BT(t):
            if t is None:
                return ''
            return '(%s|%s)' % (hash_BT(t.left), hash_BT(t.right))
        
        results = [{} for _ in range(0, n + 1)]
        
        def all_BT(n):
            if n < 0 or n % 2 == 0:
                return []
            if n == 1:
                return [TreeNode(0)]
            for t in all_BT(n - 2):
                leaves, S = [], [t]
                while len(S) > 0:
                    node = S.pop()
                    if node.left is None:
                        leaves.append(node)
                    else:
                        S.append(node.left)
                        S.append(node.right)
                for node in leaves:
                    node.left, node.right = TreeNode(0), TreeNode(0)
                    key = hash_BT(t)
                    if not key in results[n]:
                        results[n][key] = copy_BT(t)
                    node.left, node.right = None, None
            return list(results[n].values())
        return all_BT(n)
