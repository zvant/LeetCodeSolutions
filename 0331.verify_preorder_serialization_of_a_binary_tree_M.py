'''
https://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/
2016/05
56 ms
'''

class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        
        nodes = preorder.split(',')
        count = 0
        for node in nodes:
            if count < 0:
                return False
            
            if node == '#':
                count -= 1
            else:
                count += 1
        
        return count == -1
