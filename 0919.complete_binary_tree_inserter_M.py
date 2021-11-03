# https://leetcode.com/problems/complete-binary-tree-inserter/
# 2021/10
# 60 ms

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class CBTInserter:
    def __init__(self, root: Optional[TreeNode]):
        self.root = root
        self.Q1, self.Q2 = [self.root], []
        while True:
            for n in self.Q1:
                for child in [n.left, n.right]:
                    if not child is None:
                        self.Q2.append(child)
            if len(self.Q2) < 2 * len(self.Q1):
                break
            else:
                self.Q1 = self.Q2
                self.Q2 = []
    def insert(self, val: int) -> int:
        node = TreeNode(val)
        diff = len(self.Q1) * 2 - len(self.Q2)
        p = self.Q1[(diff + 1) // 2 * -1]
        if diff % 2 == 0:
            p.left = node
        else:
            p.right = node
        self.Q2.append(node)
        if len(self.Q2) >= 2 * len(self.Q1):
            self.Q1 = self.Q2
            self.Q2 = []
        return p.val
    def get_root(self) -> Optional[TreeNode]:
        return self.root

# Your CBTInserter object will be instantiated and called as such:
# obj = CBTInserter(root)
# param_1 = obj.insert(val)
# param_2 = obj.get_root()