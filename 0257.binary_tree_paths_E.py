'''
https://leetcode.com/problems/binary-tree-paths/description/
2015/09
64 ms
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @return {string[]}
    def binaryTreePaths(self, root):
        self.paths = []
        self.searchPaths(root, [])
        return self.paths
    
    def searchPaths(self, root, prev_path):
        if root != None:
            prev_path.append(str(root.val))
            
            if root.left == None and root.right == None:
                self.paths.append('->'.join(prev_path))
            else:
                if root.left != None:
                    self.searchPaths(root.left, prev_path[:])
                if root.right != None:
                    self.searchPaths(root.right, prev_path[:])
