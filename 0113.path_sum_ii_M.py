'''
https://leetcode.com/problems/path-sum-ii/description/
2015/08
112 ms
'''

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    # @param {TreeNode} root
    # @param {integer} sum
    # @param {integer[]} path
    # @return {integer[][]}
    def searchPath(self, root, summary, path):
        if root == None:
            return None
        summary += root.val
        path.append(root.val)
        if root.left == None and root.right == None:
            if summary == self.summary:
                self.paths.append(path)
        else:
            self.searchPath(root.left, summary, path[:])
            self.searchPath(root.right, summary, path[:])
    
    # @param {TreeNode} root
    # @param {integer} sum
    # @return {integer[][]}
    def pathSum(self, root, summary):
        self.summary = summary
        self.paths = []
        self.searchPath(root, 0, [])
        return self.paths
